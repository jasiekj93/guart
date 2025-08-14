#pragma once

/**
 * @file BarGraph.hpp
 * @author Adrian Szczepanski
 * @date 13-08-2025
 */

#include <string>
#include <vector>

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class BarGraph : public Base
    {
    public:
        explicit BarGraph(Canvas& canvas);

    protected:
        using Labels = std::vector<std::string>;
        using Values = std::vector<unsigned int>;
        using Coordinates = std::vector<unsigned int>;

        void drawWidget(const Drawable&, Canvas&) const override;

        Coordinates drawXAxis(const Drawable&, Canvas&, const Labels&, unsigned int maxValueWidth) const;
        Coordinates drawYAxis(const Drawable&, Canvas&, const Values&, unsigned int maxValueWidth) const;
        void drawXAxisTitle(const Drawable&, Canvas&) const;
        void drawYAxisTitle(const Drawable&, Canvas&) const;
        void drawError(const Drawable&, Canvas&) const;
        void drawBars(const Drawable&, Canvas&, const Coordinates& x, const Coordinates& y) const;

        Values getValues(const Drawable&) const;
        Labels getLabels(const Drawable&) const;
        unsigned int getMaxValueWidth(const Values&) const;
        Coordinates sortYCoordinates(const Values&, const Coordinates& yCoordinates) const;
    };

} 