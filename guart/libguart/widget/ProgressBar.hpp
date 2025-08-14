#pragma once

/**
 * @file ProgressBar.hpp
 * @author Adrian Szczepanski
 * @date 14-08-2025
 */

#include <string>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class ProgressBar : public Widget
    {
    public:
        ProgressBar(const Point& position, Dimensions::Width, unsigned int maxValue, unsigned int value = 0);

        void setValue(unsigned int value);
        void setMaxValue(unsigned int maxValue);
        void increase(unsigned int increment);
        void decrease(unsigned int decrement);

        inline auto getValue() const { return value; }
        inline auto getMaxValue() const { return maxValue; }
        inline auto getWidth() const { return width; }
        unsigned int getPercentageValue() const;

        inline std::string_view getType() const override { return "ProgressBar"; }

    private:
        unsigned int value;
        unsigned int maxValue;
        Dimensions::Width width;
    };
} 