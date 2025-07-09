#pragma once

/**
 * @file TextBox.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class TextBox : public Base 
    {
    public:
        explicit TextBox(Canvas& canvas);

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;
    };

} 