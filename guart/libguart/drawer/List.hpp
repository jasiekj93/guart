#pragma once

/**
 * @file List.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class List : public Base 
    {
    public:
        explicit List(Canvas& canvas);

        void draw(const Drawable&) const override;
    };

} 