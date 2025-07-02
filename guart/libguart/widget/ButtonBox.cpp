#include "ButtonBox.hpp"

using namespace guart;
using namespace guart::widget;

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