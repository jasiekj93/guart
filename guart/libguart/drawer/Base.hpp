#pragma once

/**
 * @file Base.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/Drawer.hpp>
#include <libguart/Widget.hpp>
#include <libguart/Canvas.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::drawer
{
    class Base : public Drawer
    {
    public:
        explicit Base(Canvas&);
        virtual ~Base() = default;

        // Draws the widget on the screen
        virtual void draw(const Widget&) const override = 0;

    protected:
        void drawBorder(const Point&, const Dimensions&) const; 
        void drawBoldBorder(const Point&, const Dimensions&) const; 

        void drawBorderTitle(const Point&, const Dimensions&, std::string_view title) const; 

        inline Canvas& getCanvas() const { return canvas; }

    private:
        Canvas& canvas; 
    };
}