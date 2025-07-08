#pragma once

/**
 * @file Line.hpp
 * @author Adrian Szczepanski
 * @date 02-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class Line : public Base 
    {
    public:
        explicit Line(Canvas&);

        void draw(const Widget&) const override;
    };

} 