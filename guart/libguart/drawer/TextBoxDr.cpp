#include "TextBox.hpp"
#include <libguart/widget/TextBox.hpp>

using namespace guart;
using namespace guart::drawer;

TextBox::TextBox(Canvas& canvas)
    : Base(canvas)
{
}

void TextBox::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& textBox = static_cast<const widget::TextBox&>(drawable);
    auto& text = textBox.getText();

    if (text.empty())
        return;

    auto& out = canvas.getOutput();

    auto position = textBox.getPosition();
    canvas.moveCursor(position);

    etl::istring::size_type pos = 0;
    etl::istring::size_type prev = 0;

    while ((pos = text.find('\n', prev)) != etl::istring::npos)
    {
        out << text.substr(prev, pos - prev);
        prev = pos + 1; 
        position.y += 1; // Move to the next line

        canvas.moveCursor(position);
    }

    out << text.substr(prev);
}
