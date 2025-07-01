#include "Widget.hpp"
#include "Parent.hpp"

using namespace guart;

Widget::Widget(const Point& position)
    : position(position)
    , parent(nullptr)
{
}