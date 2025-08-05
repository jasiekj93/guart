#pragma once

/**
 * @file Point.hpp
 * @author Adrian Szczepanski
 * @date 30-06-2025
 */

namespace guart
{
    struct Point
    {
        using X = unsigned int;
        using Y = unsigned int;

        X x;
        Y y;

        Point(X x, Y y)
            : x(x), y(y) {}

        Point operator+(const Point& other) const
        {
            return Point(x + other.x, y + other.y);
        }

        Point& operator+=(const Point& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
    };
}