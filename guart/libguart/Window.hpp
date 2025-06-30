#pragma once

#include <libguart/Point.hpp>
#include <libguart/Dimensions.hpp>

namespace guart
{
    class Window
    {
    public:
        Window(const Point&, const Dimensions&, bool isBold = false);

        void draw() const;
       
    private:
        Point position;
        Dimensions dimensions;
        bool isBold;
    };
}