#include "ButtonBox.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

ButtonBox::ButtonBox(const Point& p, const Dimensions& d, const Buttons& buttons, bool addBorder)
    : Widget(p)
    , buttons(buttons)
    , dimensions(d)
    , addBorder(addBorder)
{
    if(not buttons.empty())
        activeIndex = 0; 
}

void ButtonBox::addButton(const etl::string_view &button)
{
    buttons.push_back(button);

    if(activeIndex < 0)
        activeIndex = 0; 
}

bool ButtonBox::setActiveButton(int index)
{
    if (index < 0 || index >= static_cast<int>(buttons.size()))
        return false;
    activeIndex = index;
    return true;
}

void ButtonBox::processKey(const etl::string_view& input)
{
    if (input.empty())
        return;

    if (input == key::LEFT)
    {
        if (activeIndex > 0)
        {
            setActiveButton(activeIndex - 1);
            invalidate();
        }
    }
    else if (input == key::RIGHT)
    {
        if (activeIndex < static_cast<int>(buttons.size()) - 1)
        {
            setActiveButton(activeIndex + 1);
            invalidate();
        }
    }
    else if (input == key::CR or 
             input == key::CR_NL or 
             input == key::NEW_LINE) 
    {
        if (onAction)
            onAction(*this, buttons[activeIndex]);
    }
}
