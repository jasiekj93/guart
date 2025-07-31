#pragma once

/**
 * @file Slider.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <string>
#include <vector>

#include <libguart/widget/List.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class Slider : public List
    {
    public:
        Slider(const Point&, const Dimensions&, const Items& items = {}, bool addBorder = false);

        inline virtual std::string_view getType() const override { return "Slider"; }
    
    protected:
        void processActiveIndexChange() override; 
    };
} 