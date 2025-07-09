#include "Slider.hpp"

using namespace guart;
using namespace guart::widget;

Slider::Slider(const Point& p, const Dimensions& d, const Items &items, bool addBorder)
    : List(p, d, items, addBorder)
{
}

void Slider::processActiveIndexChange()
{
    if(onAction)
        onAction(*this, getItems()[getActiveIndex()]);
}
