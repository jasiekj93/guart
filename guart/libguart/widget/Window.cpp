#include "Window.hpp"

using namespace guart;
using namespace guart::widget;

Window::Window(const Point& p, const Dimensions& d)
    : Widget(p)
    , dimensions(d)
{
}

void Window::resize(const Dimensions& d)
{
    dimensions = d;
}