#pragma once

/**
 * @file Window.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer
{
    class Window : public Base
    {
    public:
        explicit Window(Canvas& canvas);

        void draw(const Widget& window) const override;
    };
}