#include "Slider.hpp"
#include <libguart/widget/Slider.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

Slider::Slider(Canvas& canvas)
    : Base(canvas)
{
}

void Slider::draw(const Drawable& drawable) const
{
    auto& slider = dynamic_cast<const widget::Slider&>(drawable);
    
    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    if (slider.hasBorder())
    {
        drawBorder(slider.getPosition(), slider.getDimensions());
        drawBorderTitle(slider.getPosition(), slider.getDimensions(), slider.getTitle());
    }

    auto& items = slider.getItems();
    auto position = slider.getPosition() + Point {1, 1}; // Offset for border
    auto height = slider.getDimensions().height; // Adjust height for border

    for(auto i = 0; i < items.size(); ++i)
    {
        if(i >= height / 2)
            break;

        auto& item = items[i];
        auto itemPosition = Point(position.x, position.y + i * 2);

        canvas.moveCursor(itemPosition);

        if(i == slider.getActiveIndex()) 
            out << BLACK_HORIZONTAL_RECTANGLE << ' ';
        else if(i == items.size() - 1)
            out << border::HORIZONTAL_DOWN << ' ';
        else if(i == 0)
            out << border::HORIZONTAL_UP << ' ';
        else
            out << border::CROSS << ' ';

        if (i == slider.getActiveIndex() and slider.isFocused())
            out << style::REVERSE;

        out << item;

        if (i == slider.getActiveIndex() and slider.isFocused())
            out << style::NORMAL;
        
        if(i < items.size() - 1)
        {
            canvas.moveCursor(Point(position.x, position.y + (i * 2) + 1));
            out << border::VERTICAL;
        }
    }

    out.flush();
}