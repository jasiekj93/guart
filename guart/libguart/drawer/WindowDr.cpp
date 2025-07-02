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

    int labelPosition = (window.getDimensions().width / 2) - (window.getLabel().size() / 2);

    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    canvas.moveCursor({ window.getPosition().x + labelPosition, window.getPosition().y });
    out << window.getLabel();
    out.flush();
}
