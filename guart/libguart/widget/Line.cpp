#include "Line.hpp"

using namespace guart;
using namespace guart::widget;

Line::Line(const Point& p, Dimensions::Width w, bool isDouble)
    : Widget(p)
    , width(w)
    , isDoubleLine(isDouble)
{
}