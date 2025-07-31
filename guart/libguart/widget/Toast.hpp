#pragma once

/**
 * @file Toast.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#ifndef GUART_WIDGET_TOAST_MESSAGE_LIMIT
#define GUART_WIDGET_TOAST_MESSAGE_LIMIT 64
#endif

#include <libguart/Widget.hpp>

namespace guart::widget
{
    class Toast : public Widget
    {
    public:
        static constexpr size_t MESSAGE_LIMIT = GUART_WIDGET_TOAST_MESSAGE_LIMIT;

        using Message = etl::string<MESSAGE_LIMIT>;

        Toast(const Point& position, etl::string_view message);

        inline etl::string_view getType() const override { return "Toast"; }
        inline bool isModal() const override { return true; }
        inline bool isFocusable() const override { return true; }
        inline auto& getMessage() const { return message; }

        void processKey(const etl::string_view&) override;

    private:
        Message message;
    };
}