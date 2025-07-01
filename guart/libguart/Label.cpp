#include "Label.hpp"
#include "Window.hpp"

using namespace guart;

Label::Label(const Point &position, const std::string_view &text)
    : Widget(position)
    , text(text)
{
}

void Label::invalidate() const
{
    if(not parent)
        return;

    parent->moveCursor(position);
    auto &out = parent->getOutput();
    out << text;
    out.flush();
}
