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
        using Buttons = std::vector<std::string_view>;

        ButtonBox(const Point&, const Dimensions&, const Buttons& buttons, bool addBorder = true);

        void addButton(const std::string_view& button);
        bool setActiveButton(int index);

        inline auto& getDimensions() const { return dimensions; }
        inline auto getActiveButton() const { return activeIndex; }
        inline auto getButtons() const { return buttons; }
        inline bool hasBorder() const { return addBorder; }

        inline void setTitle(std::string_view l) { title = l; }
        inline std::string_view getTitle() const { return title; }

        inline std::string_view getType() const override { return "ButtonBox"; }
        inline bool isFocusable() const { return true; }

        void processInput(const std::string_view&) override;

    private:
        Buttons buttons;
        std::string title;
        int activeIndex = -1;
        Dimensions dimensions;
        bool addBorder;
    };
}