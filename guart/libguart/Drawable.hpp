#pragma once

/**
 * @file Drawable.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <string>

#include <libguart/Drawer.hpp>

namespace guart
{
    class Drawable
    {
    public:
        virtual ~Drawable() = default;

        virtual void invalidate() const;

        virtual inline void setDrawer(Drawer* d) { drawer = d; }

        virtual std::string_view getType() const = 0;

    protected:
        Drawer* drawer = nullptr;
    };
}