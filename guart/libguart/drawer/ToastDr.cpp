#include "Toast.hpp"
#include <libguart/widget/Toast.hpp>

using namespace guart::drawer;

Toast::Toast(Canvas& canvas)
    : Base(canvas)
{
}

void Toast::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& toast = static_cast<const guart::widget::Toast&>(drawable);
    auto& out = canvas.getOutput();

    Dimensions::Width width = toast.getMessage().size() + 2;

    drawBoldBorder(toast.getPosition(), Dimensions{ width, 1});
    canvas.moveCursor(toast.getPosition() + Point{ 2, 1 });
    
    out << toast.getMessage();
}
