#include "Window.hpp"
#include <libguart/widget/Window.hpp>

using namespace guart::drawer;

Window::Window(Canvas& canvas)
    : Base(canvas)
{
}

void Window::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& window = static_cast<const guart::widget::Window&>(drawable);

    drawBoldBorder(window.getPosition(), window.getDimensions());
    drawBorderTitle(window.getPosition(), window.getDimensions(), window.getTitle());
}
