#pragma once

/**
 * @file TextField.hpp
 * @author Adrian Szczepanski
 * @date 21-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class TextField : public Base
    {
    public:
        explicit TextField(Canvas& canvas);

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;
    };

} 