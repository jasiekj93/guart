#include "List.hpp"
#include <libguart/widget/List.hpp>
#include <libguart/Charset.hpp>

using namespace guart::drawer;

List::List(Canvas& canvas)
    : Base(canvas)
{
}

void List::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& list = dynamic_cast<const guart::widget::List&>(drawable);
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
            out << style::REVERSE;

        drawItem(drawable, out, item, i);

        if (i == list.getActiveIndex() and list.isFocused())
            out << style::NORMAL;
        
        displayedItems++;
    }
}

void List::drawItem(const Drawable&, Output& out, std::string_view item, int index) const
{
    out << item;
}