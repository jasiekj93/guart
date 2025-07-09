#include "Line.hpp"
#include <libguart/widget/Line.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

Line::Line(Canvas& canvas)
    : Base(canvas)
{
}

void Line::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& line = static_cast<const widget::Line&>(drawable);
    auto& out = canvas.getOutput();

    canvas.moveCursor(line.getPosition());

    for(auto i = 0; i < line.getWidth(); ++i)
        out << (line.isDouble() ? border::bold::HORIZONTAL : border::HORIZONTAL);
}

