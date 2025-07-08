#include "Line.hpp"
#include <libguart/widget/Line.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

Line::Line(Canvas& canvas)
    : Base(canvas)
{
}

void Line::draw(const Widget& widget) const
{
    auto& line = static_cast<const widget::Line&>(widget);

    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    canvas.moveCursor(line.getPosition());

    for(auto i = 0; i < line.getWidth(); ++i)
        out << (line.isDouble() ? border::bold::HORIZONTAL : border::HORIZONTAL);

    out.flush();
}

