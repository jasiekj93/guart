#include "ButtonBox.hpp"
#include "Parent.hpp"
#include "Charset.hpp"

using namespace guart;

ButtonBox::ButtonBox(const Point& p, const Dimensions& d, const std::vector<std::string_view>& buttons, bool addBorder)
    : Widget(p)
    , buttons(buttons)
    , dimensions(d)
    , addBorder(addBorder)
{
}

void ButtonBox::addButton(const std::string_view &button)
{
    buttons.push_back(button);
}

bool ButtonBox::setActiveButton(int index)
{
    if (index < 0 || index >= static_cast<int>(buttons.size()))
        return false;
    activeIndex = index;
    return true;
}

void ButtonBox::invalidate() const
{
    if (not parent)
        return;

    if (addBorder)
        drawBorder();

    drawButtons();
}

void ButtonBox::drawBorder() const
{
    parent->moveCursor(position);
    auto &out = parent->getOutput();

    out << border::TOP_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::HORIZONTAL;

    out << border::TOP_RIGHT;

    for(auto i = 0; i < dimensions.height; i++)
    {
        parent->moveCursor({ position.x, position.y + i + 1 });
        out << border::VERTICAL;

        for(auto j = 0; j < dimensions.width; j++)
            out << ' ';

        out << border::VERTICAL;
    }

    parent->moveCursor({ position.x, position.y + dimensions.height + 1 });
    out << border::LOWER_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::HORIZONTAL;

    out << border::LOWER_RIGHT;
}

void ButtonBox::drawButtons() const
{
    if (buttons.empty())
        return;

    auto buttonWidth = dimensions.width / buttons.size();
    auto buttonHeight = dimensions.height;

    for (size_t i = 0; i < buttons.size(); ++i)
    {
        auto buttonPosition = Point(position.x + i * buttonWidth + 1, position.y + 1);
        parent->moveCursor(buttonPosition);
        auto &out = parent->getOutput();

        if(i == activeIndex)
            out << "\e[7m";
        out << '[' << buttons[i] << ']';

        if(i == activeIndex)
            out << "\e[m";

        // Fill the rest of the button space with spaces
        for (int j = buttons[i].size(); j < buttonWidth - 1; ++j)
            out << ' ';
    }
}
