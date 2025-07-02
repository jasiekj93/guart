#pragma once

/**
 * @file Canvas.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/Output.hpp>
#include <libguart/Point.hpp>

namespace guart
{
    class Canvas
    {
    public:
        ~Canvas() = default;

        virtual Output& getOutput() const = 0;
        virtual void moveCursor(const Point& p) const = 0;
        virtual void clear() const = 0;
    };
}