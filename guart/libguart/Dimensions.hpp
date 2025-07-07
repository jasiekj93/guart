#pragma once

/**
 * @file Dimensions.hpp
 * @author Adrian Szczepanski
 * @date 30-06-2025
 */

namespace guart
{
    struct Dimensions
    {
        using Width = unsigned int;
        using Height = unsigned int;

        Width width;
        Height height;
    };
}