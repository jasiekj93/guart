#include "Window.hpp"
#include "Charset.hpp"
#include "Screen.hpp"

using namespace guart;

Window::Window(const Point& p, const Dimensions& d)
    : Widget(p)
    , dimensions(d)
{
}

void Window::invalidate() const
{
    drawHeader();
    drawBody();
    drawFooter();

    invalidateWidgets();
}

void Window::resize(const Dimensions& d)
{
    dimensions = d;
}

void Window::moveCursor(const Point& p) const
{
    if (not parent)
        return;

    parent->moveCursor({ position.x + p.x + 1, position.y + p.y + 1 });
}

Output &Window::getOutput() const
{
    return parent->getOutput();
}

void Window::drawHeader() const
{
    if (not parent)
        return;

    auto& out = parent->getOutput();
    parent->moveCursor(position);

    auto topWidth = (dimensions.width - label.size())/2;

    out << border::bold::TOP_LEFT;

    for(auto j = 0; j < topWidth; j++)
        out << border::bold::HORIZONTAL;

    out << label;

    if(label.size() % 2 != 0)
        out << ' ';

    for(auto j = 0; j < topWidth; j++)
        out << border::bold::HORIZONTAL;

    out << border::bold::TOP_RIGHT;
}

void Window::drawBody() const
{
    if (not parent)
        return;

    auto& out = parent->getOutput();

    for(auto i = 0; i < dimensions.height; i++)
    {
        parent->moveCursor({ position.x, position.y + 1 + i });
        out << border::bold::VERTICAL;

        for(auto j = 0; j < dimensions.width; j++)
            out << ' ';

        out << border::bold::VERTICAL;
        out << "\r\n";
    }
    
    out.flush();
}

void Window::drawFooter() const
{
    if (not parent)
        return;

    auto& out = parent->getOutput();
    parent->moveCursor({ position.x, position.y + dimensions.height + 1});

    out << border::bold::LOWER_LEFT;

    for(auto j = 0; j < dimensions.width; j++)
        out << border::bold::HORIZONTAL;

    out << border::bold::LOWER_RIGHT;
    out.flush();
}
