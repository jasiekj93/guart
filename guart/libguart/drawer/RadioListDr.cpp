#include "RadioList.hpp"
#include <libguart/widget/RadioList.hpp>
#include <libguart/Charset.hpp>

using namespace guart::drawer;

RadioList::RadioList(Canvas& canvas)
    : Base(canvas)
{
}

void RadioList::draw(const Drawable& drawable) const
{
    auto& list = dynamic_cast<const guart::widget::RadioList&>(drawable);
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

        if (list.getSelectedIndex() == i)
            out << RADIO_BUTTON_CHECKED << ' ';
        else
            out << RADIO_BUTTON_UNCHECKED << ' ';

        out << item;

        if (i == list.getActiveIndex() and list.isFocused())
            out << control::REVERSE_OFF;
        
        displayedItems++;
    }

    out.flush();
}