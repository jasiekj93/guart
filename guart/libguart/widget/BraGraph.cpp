#include "BarGraph.hpp"

using namespace guart;
using namespace guart::widget;

BarGraph::BarGraph(const Point& p, const Dimensions& d, bool startAtZero, 
    std::string_view xTitle, std::string_view yTitle, const Items& items)
    : Widget(p) 
    , dimensions(d)
    , startAtZero(startAtZero)
    , xTitle(xTitle)
    , yTitle(yTitle)
    , items(items)
{
}