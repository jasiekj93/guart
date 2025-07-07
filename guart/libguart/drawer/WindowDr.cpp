#include "Window.hpp"
#include <libguart/widget/Window.hpp>

using namespace guart::drawer;

Window::Window(Canvas& canvas)
    : Base(canvas)
{
}

void Window::draw(const Widget& widget) const
{
    auto& window = static_cast<const guart::widget::Window&>(widget);

    drawBoldBorder(window.getPosition(), window.getDimensions());
    drawBorderTitle(window.getPosition(), window.getDimensions(), window.getTitle());
}
