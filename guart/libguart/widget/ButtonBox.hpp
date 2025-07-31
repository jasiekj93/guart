#pragma once

/**
 * @file ButtonBox.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#ifndef GUART_WIDGET_BUTTONBOX_TITLE_LIMIT
#define GUART_WIDGET_BUTTONBOX_TITLE_LIMIT 16
#endif 

#ifndef GUART_WIDGET_BUTTONBOX_BUTTONS_LIMIT
#define GUART_WIDGET_BUTTONBOX_BUTTONS_LIMIT 8
#endif

#include <etl/vector.h>
#include <etl/string.h>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    //TODO Window jako border
    class ButtonBox : public Widget
    {
    public:
        static constexpr size_t TITLE_LIMIT = GUART_WIDGET_BUTTONBOX_TITLE_LIMIT;
        static constexpr size_t BUTTONS_LIMIT = GUART_WIDGET_BUTTONBOX_BUTTONS_LIMIT;

        using Buttons = etl::vector<etl::string_view, BUTTONS_LIMIT>;

        ButtonBox(const Point&, const Dimensions&, const Buttons& buttons, bool addBorder = true);

        void addButton(const etl::string_view& button);
        bool setActiveButton(int index);

        inline auto& getDimensions() const { return dimensions; }
        inline auto getActiveButton() const { return activeIndex; }
        inline auto getButtons() const { return buttons; }
        inline bool hasBorder() const { return addBorder; }

        inline void setTitle(etl::string_view l) { title = l; }
        inline etl::string_view getTitle() const { return title; }

        inline etl::string_view getType() const override { return "ButtonBox"; }
        inline bool isFocusable() const { return true; }

        void processKey(const etl::string_view&) override;

    private:
        Buttons buttons;
        etl::string<TITLE_LIMIT> title;
        int activeIndex = -1;
        Dimensions dimensions;
        bool addBorder;
    };
}