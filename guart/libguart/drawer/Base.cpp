#include "Base.hpp"
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

Base::Base(Canvas& canvas)
    : canvas(canvas)
{
}

void Base::drawBorder(const Point& point, const Dimensions& dimensions) const
{
    canvas.moveCursor(point);
    auto &out = canvas.getOutput();

    out << border::TOP_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::HORIZONTAL;

    out << border::TOP_RIGHT;

    for(auto i = 0; i < dimensions.height; i++)
    {
        canvas.moveCursor({ point.x, point.y + i + 1 });
        out << border::VERTICAL;

        for(auto j = 0; j < dimensions.width; j++)
            out << ' ';

        out << border::VERTICAL;
    }

    canvas.moveCursor({ point.x, point.y + dimensions.height + 1 });
    out << border::LOWER_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::HORIZONTAL;

    out << border::LOWER_RIGHT;
    out.flush();
}

void Base::drawBoldBorder(const Point& point, const Dimensions& dimensions) const
{
    canvas.moveCursor(point);
    auto &out = canvas.getOutput();

    out << border::bold::TOP_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::bold::HORIZONTAL;

    out << border::bold::TOP_RIGHT;

    for(auto i = 0; i < dimensions.height; i++)
    {
        canvas.moveCursor({ point.x, point.y + i + 1 });
        out << border::bold::VERTICAL;

        for(auto j = 0; j < dimensions.width; j++)
            out << ' ';

        out << border::bold::VERTICAL;
    }

    canvas.moveCursor({ point.x, point.y + dimensions.height + 1 });
    out << border::bold::LOWER_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::bold::HORIZONTAL;

    out << border::bold::LOWER_RIGHT;
    out.flush();
}
