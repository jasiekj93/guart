#pragma once

/**
 * @file Drawer.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

namespace guart
{
    class Drawable;

    class Drawer
    {
    public:
        virtual ~Drawer() = default;

        virtual void draw(const Drawable&) const = 0;
    };
}