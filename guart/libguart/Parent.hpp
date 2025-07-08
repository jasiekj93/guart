#pragma once

/**
 * @file Parent.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#include <libguart/Point.hpp>

namespace guart
{
    class Widget;

    class Parent 
    {
    public:
        virtual ~Parent() = default;

        virtual void removeWidget(Widget* child) = 0;

        virtual Point getContentPosition() const { return Point{0, 0}; }
    };
}