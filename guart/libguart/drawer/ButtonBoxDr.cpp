#include "ButtonBox.hpp"
#include <libguart/widget/ButtonBox.hpp>

using namespace guart;
using namespace guart::drawer;

ButtonBox::ButtonBox(Canvas& canvas)
    : Base(canvas)
{
}

void ButtonBox::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& buttonBox = static_cast<const guart::widget::ButtonBox&>(drawable);
    auto& out = canvas.getOutput();
    auto buttonStart = buttonBox.getPosition();

    if (buttonBox.hasBorder())
    {
        drawBorder(buttonBox.getPosition(), buttonBox.getDimensions());
        drawBorderTitle(buttonBox.getPosition(), buttonBox.getDimensions(), buttonBox.getTitle());

        buttonStart = Point(buttonBox.getPosition().x + 1, buttonBox.getPosition().y + 1);
    }

    auto buttons = buttonBox.getButtons();

    if (buttons.empty())
        return;

    canvas.moveCursor(buttonStart);

    for (size_t i = 0; i < buttons.size(); ++i)
    {
        auto buttonWidth = buttonBox.getButtons()[i].size() + 2;

        if(i == buttonBox.getActiveButton() and buttonBox.isFocused())
            out << "\e[7m";
        out << '[' << buttons[i] << ']';

        if(i == buttonBox.getActiveButton() and buttonBox.isFocused())
            out << "\e[m";

        // // Fill the rest of the button space with spaces
        // for (int j = buttons[i].size(); j < buttonWidth - 1; ++j)
            out << ' ';
    }
}