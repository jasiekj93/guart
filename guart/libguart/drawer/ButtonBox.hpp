#pragma once

/**
 * @file ButtonBox.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class ButtonBox : public Base 
    {
    public:
        explicit ButtonBox(Canvas& canvas);

        void draw(const Drawable&) const override;
    };

} 