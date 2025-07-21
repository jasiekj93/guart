#include "Calendar.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

Calendar::Calendar(const Point &position, const Date& date)
    : Widget(position)
    , date(date)
{
}

void Calendar::processKey(const std::string_view& input)
{
    if(input.empty())
        return;

    if (input == key::UP)
        date -= DateSpan{0, 0, 7}; 
    else if(input == key::DOWN)
        date += DateSpan{0, 0, 7}; 
    else if (input == key::LEFT)
        date -= DateSpan{0, 0, 1}; 
    else if (input == key::RIGHT)
        date += DateSpan{0, 0, 1}; 
    else if (input == key::HOME)
        date -= DateSpan{1, 0, 0}; 
    else if (input == key::END)
        date += DateSpan{1, 0, 0}; 
    else if (input == key::PAGE_UP)
        date -= DateSpan{0, 1, 0};
    else if (input == key::PAGE_DOWN)
        date += DateSpan{0, 1, 0};
    else if(input == key::CR or input == key::NEW_LINE or input == key::CR_NL)
    {
        if(onAction)
            onAction(*this, date.toString()); 
    }
    else
        return;
    
    invalidate();
}