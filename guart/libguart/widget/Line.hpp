#pragma once

/**
 * @file Line.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class Line : public Widget
    {
    public:
        Line(const Point&, Dimensions::Width, bool isDouble = false);

        inline etl::string_view getType() const override { return "Line"; }
        inline auto getWidth() const { return width; }
        inline bool isDouble() const { return isDoubleLine; }

    private:
        Dimensions::Width width;
        bool isDoubleLine;
    };
}