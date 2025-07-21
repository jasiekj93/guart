#include "TextField.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

TextField::TextField(const Point& position, size_t len, const std::string_view& text)
    : Widget(position)
    , text(text)
    , length(len)
{
}

void TextField::processKey(const std::string_view& input)
{
    if(input.empty())
        return; 

    if(input == key::BACKSPACE) // Backspace
    {
        if(!text.empty())
            text.pop_back();

        invalidate(); 
    }
    else if(input == key::CR_NL or
        input == key::CR or
        input == key::NEW_LINE) 
    {
        onAction(*this, text);
    }
    else if(input.size() == 1)
    {
        if(input[0] >= ' ' and input[0] <= '~')
        {
            if(text.size() >= length)
                return; 

            text += input[0]; 
            invalidate(); 
        }
    }
}
