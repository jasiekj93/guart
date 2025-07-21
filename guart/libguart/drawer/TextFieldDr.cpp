#include "TextField.hpp"
#include <libguart/widget/TextField.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

TextField::TextField(Canvas& canvas)
    : Base(canvas)
{
}

void TextField::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& textField = static_cast<const widget::TextField&>(drawable);
    auto& out = canvas.getOutput();

    drawBorder(textField.getPosition(), 
        Dimensions {(Dimensions::Width)textField.getLength(), 1}); 

    if(textField.isFocused())
        out << style::REVERSE;

    canvas.moveCursor(textField.getPosition() + Point{1, 1}); 
    out << textField.getText();

    if(textField.getText().size() < textField.getLength())
    {
        if(textField.isFocused())
        {
            out << style::BLINK; // Use BLINK style for empty space
            out << DARK_SHADE;
            out << style::BLINK_OFF;
        }
    }


    for(size_t i = textField.getText().size() + 1; i < textField.getLength(); i++)
        out << ' '; // Fill remaining space with spaces

    if(textField.isFocused())
        out << style::NORMAL;
}

