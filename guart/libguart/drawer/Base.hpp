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

        virtual void draw(const Drawable&) const override = 0;

    protected:
        void drawBorder(const Point&, const Dimensions&) const; 
        void drawBoldBorder(const Point&, const Dimensions&) const; 

        void drawBorderTitle(const Point&, const Dimensions&, std::string_view title) const; 

        void drawScrollBar(const Point&, const Dimensions&, int activeIndex, int totalItems) const;

        inline Canvas& getCanvas() const { return canvas; }

    private:
        Canvas& canvas; 
    };
}