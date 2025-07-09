#pragma once

/**
 * @file RadioList.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class RadioList : public Base 
    {
    public:
        explicit RadioList(Canvas& canvas);

        void draw(const Drawable&) const override;
    };

} 