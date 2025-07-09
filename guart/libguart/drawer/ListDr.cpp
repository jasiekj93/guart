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

    for(auto i = 0; i < items.size(); ++i)
    {
        auto& item = items[i];
        auto itemPosition = Point(position.x, position.y + i);
        
        canvas.moveCursor(itemPosition);

        if (i == list.getActiveIndex() and list.isFocused())
            out << control::REVERSE_ON;

        out << item;

        if (i == list.getActiveIndex() and list.isFocused())
            out << control::REVERSE_OFF;
    }

    out.flush();
}
