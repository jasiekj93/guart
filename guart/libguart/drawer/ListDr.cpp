#include "List.hpp"
#include <libguart/widget/List.hpp>
#include <libguart/Charset.hpp>

using namespace guart::drawer;

List::List(Canvas& canvas)
    : Base(canvas)
{
}

void List::draw(const Drawable& drawable) const
{
    auto& list = dynamic_cast<const guart::widget::List&>(drawable);
    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    if (list.hasBorder())
    {
        drawBorder(list.getPosition(), list.getDimensions());
        drawBorderTitle(list.getPosition(), list.getDimensions(), list.getTitle());
    }

    auto& items = list.getItems();
    auto position = list.getPosition() + Point {1, 1}; // Offset for border
    auto height = list.getDimensions().height; // Adjust height for border
    auto displayedItems = 0;

    if(items.size() > height)
        drawScrollBar(position, list.getDimensions(), list.getActiveIndex(), items.size());

    for(auto i = list.getDisplayedIndex(); i < items.size(); ++i)
    {
        if(displayedItems >= height)
            break;

        auto& item = items[i];
        auto itemPosition = Point(position.x, position.y + displayedItems);

        canvas.moveCursor(itemPosition);

        if (i == list.getActiveIndex() and list.isFocused())
            out << control::REVERSE_ON;

        out << item;

        if (i == list.getActiveIndex() and list.isFocused())
            out << control::REVERSE_OFF;
        
        displayedItems++;
    }

    out.flush();
}

void List::drawScrollBar(const Point &position, const Dimensions &dimensions, int activeIndex, int totalItems) const
{
    if(totalItems <= dimensions.height)
        return; // No scrollbar needed

    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    canvas.moveCursor(position + Point{dimensions.width - 1, 0});
    out << BLACK_UP_POINTING_TRIANGLE;

    auto scrollBarHeight = dimensions.height - 2; 
    double ratio = static_cast<double>(activeIndex) / (totalItems - 1);
    auto scrollBarPosition = static_cast<int>(ratio * (scrollBarHeight - 1));

    for(auto i = 0; i < scrollBarHeight; ++i)
    {
        canvas.moveCursor(position + Point{dimensions.width - 1, Point::Y(i + 1)});

        if(i == scrollBarPosition)
            out << BLACK_VERTICAL_RECTANGLE; // Scrollbar indicator
        else
            out << border::VERTICAL; 
    }

    canvas.moveCursor(position + Point{dimensions.width - 1, dimensions.height - 1});
    out << BLACK_DOWN_POINTING_TRIANGLE;
}
