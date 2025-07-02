#pragma once

/**
 * @file Label.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class Label : public Base 
    {
    public:
        explicit Label(Canvas& canvas);

        void draw(const Widget& widget) const override;
    };

} 