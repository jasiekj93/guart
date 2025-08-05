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
    auto position = textField.getPosition();


    if(textField.hasBorder())
    {
        drawBorder(textField.getPosition(), 
            Dimensions {(Dimensions::Width)textField.getLength(), 1}); 

        position += Point{1, 1}; 
    }

    if(textField.isFocused())
        out << style::REVERSE;

    canvas.moveCursor(position);
    out << textField.getText();

    if(textField.getText().size() < textField.getLength() and
       textField.isFocused())
    {
        out << style::BLINK; 
        out << DARK_SHADE;
        out << style::BLINK_OFF;
    }

    for(size_t i = textField.getText().size() + 1; i < textField.getLength(); i++)
        out << '_'; 

    if(textField.isFocused())
        out << style::NORMAL;
}

