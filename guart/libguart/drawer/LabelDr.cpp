#include "Label.hpp"
#include <libguart/widget/Label.hpp>

using namespace guart;
using namespace guart::drawer;

Label::Label(Canvas& canvas)
    : Base(canvas)
{
}

void Label::draw(const Drawable& drawable) const
{
    auto& label = static_cast<const widget::Label&>(drawable);

    if (label.getText().empty())
        return;
    
    auto& canvas = getCanvas();
    auto& out = canvas.getOutput();

    canvas.moveCursor(label.getPosition());
    out << label.getText();
    out.flush();
}

