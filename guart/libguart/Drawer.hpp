#pragma once

/**
 * @file Drawer.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

namespace guart
{
    class Widget;

    class Drawer
    {
    public:
        virtual ~Drawer() = default;

        virtual void draw(const Widget& widget) const = 0;
    };
}