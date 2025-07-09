#include "Base.hpp"
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

Base::Base(Canvas& canvas)
    : canvas(canvas)
{
}

void Base::draw(const Drawable& drawable) const
{
    auto& out = canvas.getOutput();

    if(not drawable.isActive())
        out << style::DIMMER; // Apply dimmer style for inactive widgets

    drawWidget(drawable, canvas);

    if(not drawable.isActive())
        out << style::NORMAL; // Reset style after drawing

    out.flush();
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

void Base::drawBorderTitle(const Point& p, const Dimensions& d, std::string_view title) const
{
    if(title.empty())
        return;

    unsigned int titlePosition = (d.width / 2) - (title.size() / 2);
    auto &out = canvas.getOutput();

    canvas.moveCursor({ p.x + titlePosition, p.y });
    out << title;
    out.flush();
}

void Base::drawScrollBar(const Point &position, const Dimensions &dimensions, int activeIndex, int totalItems) const
{
    if(totalItems <= dimensions.height)
        return; // No scrollbar needed

    auto& out = canvas.getOutput();

    canvas.moveCursor(position + Point{dimensions.width - 1, 0});
    out << BLACK_UP_POINTING_TRIANGLE;

    auto scrollBarHeight = dimensions.height - 2; 
    double ratio = static_cast<double>(activeIndex) / (totalItems - 1);
    auto scrollBarPosition = static_cast<int>(ratio * (scrollBarHeight - 1));

    for(auto i = 0; i < scrollBarHeight; ++i)
    {
        canvas.moveCursor(position + Point{dimensions.width - 1, Point::Y(i + 1)});

        if(i == scrollBarPosition)
            out << BLACK_VERTICAL_RECTANGLE; // Scrollbar indicator
        else
            out << border::VERTICAL; 
    }

    canvas.moveCursor(position + Point{dimensions.width - 1, dimensions.height - 1});
    out << BLACK_DOWN_POINTING_TRIANGLE;
}