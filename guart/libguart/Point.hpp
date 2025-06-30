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
        using X = int;
        using Y = int;

        X x;
        Y y;
    };
}