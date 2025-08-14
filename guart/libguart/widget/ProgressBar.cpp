#include "ProgressBar.hpp"

using namespace guart;
using namespace guart::widget;

ProgressBar::ProgressBar(const Point& position, Dimensions::Width width, unsigned int maxValue, unsigned int val)
    : Widget(position)
    , value(val)
    , maxValue(maxValue)
    , width(width)
{
    if(value > maxValue)
        value = maxValue;
}

void ProgressBar::setValue(unsigned int val)
{
    value = val;
    if(value > maxValue)
        value = maxValue;
    invalidate();
}

void ProgressBar::setMaxValue(unsigned int maxValue)
{
    this->maxValue = maxValue;
    if(value > maxValue)
        value = maxValue;
    invalidate();
}

void ProgressBar::increase(unsigned int increment)
{
    setValue(value + increment);
}

void ProgressBar::decrease(unsigned int decrement)
{
    if(decrement > value)
        setValue(0);
    else
        setValue(value - decrement);
}

unsigned int ProgressBar::getPercentageValue() const
{
    if(maxValue == 0)
        return 0;
    else
        return static_cast<unsigned int>((static_cast<double>(value) / maxValue) * 100);
}
