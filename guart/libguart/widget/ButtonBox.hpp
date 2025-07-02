#pragma once

/**
 * @file ButtonBox.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <string>
#include <vector>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class ButtonBox : public Widget
    {
    public:
        ButtonBox(const Point&, const Dimensions&, const std::vector<std::string_view>& buttons, bool addBorder = true);

        void addButton(const std::string_view& button);
        bool setActiveButton(int index);

        inline auto& getDimensions() const { return dimensions; }
        inline auto getActiveButton() const { return activeIndex; }
        inline auto getButtons() const { return buttons; }
        inline bool hasBorder() const { return addBorder; }

        inline std::string_view getType() const override { return "ButtonBox"; }

    private:
        std::vector<std::string_view> buttons;
        int activeIndex = -1;
        Dimensions dimensions;
        bool addBorder;
    };
}