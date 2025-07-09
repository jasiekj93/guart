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

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;
    };
}