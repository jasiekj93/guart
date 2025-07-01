#pragma once

/**
 * @file Widget.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <libguart/Point.hpp>

namespace guart
{
    class Parent;

    class Widget
    {
    public:
        Widget(const Point& position);
        virtual ~Widget() = default;

        virtual void invalidate() const = 0;

        inline void moveTo(const Point& p) { position = p; }
        inline void setParent(Parent* p) { parent = p; }

    protected:
        Parent* parent;
        Point position;
    };
}