#pragma once

/**
 * @file Toast.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <libguart/Widget.hpp>

namespace guart::widget
{
    class Toast : public Widget
    {
    public:
        Toast(const Point& position, std::string_view message);

        inline std::string_view getType() const override { return "Toast"; }
        inline bool isModal() const override { return true; }
        inline bool isFocusable() const override { return true; }
        inline auto& getMessage() const { return message; }

        void processInput(const std::string_view&) override;

    private:
        std::string message;
    };
}