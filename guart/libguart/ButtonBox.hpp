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

namespace guart
{
    class ButtonBox : public Widget
    {
    public:
        ButtonBox(const Point&, const Dimensions&, const std::vector<std::string_view>& buttons, bool addBorder = true);

        void addButton(const std::string_view& button);
        bool setActiveButton(int index);

        void invalidate() const override;

    protected:
        void drawBorder() const;
        void drawButtons() const;

    private:
        std::vector<std::string_view> buttons;
        int activeIndex = -1;
        Dimensions dimensions;
        bool addBorder;
    };
}