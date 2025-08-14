#include "ProgressBar.hpp"
#include <libguart/widget/ProgressBar.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

ProgressBar::ProgressBar(Canvas& canvas)
    : Base(canvas)
{
}

void ProgressBar::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& progressBar = static_cast<const widget::ProgressBar&>(drawable);
    auto& out = canvas.getOutput();

    drawBorder(progressBar.getPosition(), { progressBar.getWidth(), 1 });

    canvas.moveCursor(progressBar.getPosition() + Point{1, 1});

    auto filledWidth = getFilledWidth(progressBar.getValue(), progressBar.getMaxValue(), progressBar.getWidth());

    for(auto i = 0; i < filledWidth; ++i)
        out << FULL_BLOCK;
}

unsigned int guart::drawer::ProgressBar::getFilledWidth(unsigned int value, unsigned int maxValue, Dimensions::Width width) const
{
    if(maxValue == 0 or (value > maxValue))
        return width;

    return static_cast<unsigned int>((static_cast<double>(value) / maxValue) * width);
}
