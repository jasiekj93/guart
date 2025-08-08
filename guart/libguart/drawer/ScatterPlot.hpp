#pragma once

/**
 * @file ScatterPlot.hpp
 * @author Adrian Szczepanski
 * @date 07-08-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class ScatterPlot : public Base
    {
    public:
        explicit ScatterPlot(Canvas& canvas);

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;

        void drawXAxis(const Drawable&, Canvas&, unsigned int maxX) const;
        void drawYAxis(const Drawable&, Canvas&, unsigned int maxY) const;
        void drawPoints(const Drawable&, Canvas&, unsigned int maxY, unsigned int maxX) const;
    };

} 