#include "Toast.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

Toast::Toast(const Point& position, std::string_view message)
    : Widget(position), message(message)
{
}

void Toast::processInput(const std::string_view& input)
{
    if (input == key::ENTER or input == key::ESC)
    {
        if (observer)
            observer->actionCallback(*this);

        remove(this);
    }
}