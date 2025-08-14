#pragma once

/**
 * @file ProgressBar.hpp
 * @author Adrian Szczepanski
 * @date 14-08-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class ProgressBar : public Base
    {
    public:
        explicit ProgressBar(Canvas& canvas);

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;

        unsigned int getFilledWidth(unsigned int value, unsigned int maxValue, Dimensions::Width width) const;
    };

} 