#pragma once

/**
 * @file Calendar.hpp
 * @author Adrian Szczepanski
 * @date 21-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class Calendar : public Base 
    {
    public:
        explicit Calendar(Canvas& canvas);

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;
        void moveToWeekday(Canvas& canvas, const Point&, int weekDay, int week) const;
    };

} 