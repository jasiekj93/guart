#include "Label.hpp"
#include "Window.hpp"

using namespace guart::widget;

Label::Label(const Point &position, const etl::string_view &text)
    : Widget(position)
    , text(text)
{
}