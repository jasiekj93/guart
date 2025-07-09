#include "Toast.hpp"
#include <libguart/widget/Toast.hpp>

using namespace guart::drawer;

Toast::Toast(Canvas& canvas)
    : Base(canvas)
{
}

void Toast::draw(const Drawable& drawable) const
{
    auto& toast = static_cast<const guart::widget::Toast&>(drawable);
    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    Dimensions::Width width = toast.getMessage().size() + 2;

    drawBoldBorder(toast.getPosition(), Dimensions{ width, 1});
    canvas.moveCursor(toast.getPosition() + Point{ 2, 1 });
    
    out << toast.getMessage();
    out.flush();
}
