#pragma once

/**
 * @file Base.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/Drawer.hpp>
#include <libguart/Drawable.hpp>
#include <libguart/Canvas.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::drawer
{
    class Base : public Drawer
    {
    public:
        explicit Base(Canvas&);
        virtual ~Base() = default;

        void draw(const Drawable&) const override;

    protected:
        virtual void drawWidget(const Drawable&, Canvas&) const = 0;

        void drawBorder(const Point&, const Dimensions&) const; 
        void drawBoldBorder(const Point&, const Dimensions&) const; 

        void drawBorderTitle(const Point&, const Dimensions&, etl::string_view title) const; 

        void drawScrollBar(const Point&, const Dimensions&, int activeIndex, int totalItems) const;

    private:
        Canvas& canvas; 
    };
}