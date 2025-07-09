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

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;
    };

} 