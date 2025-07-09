#include "Toast.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

Toast::Toast(const Point& position, std::string_view message)
    : Widget(position), message(message)
{
}

void Toast::processKey(const std::string_view& input)
{
    if (input == key::CR or 
        input == key::ESC or
        input == key::SPACE or
        input == key::CR_NL or
        input == key::NEW_LINE)
    {
        if (onAction)
            onAction(*this, "");

        dispose();
    }
}