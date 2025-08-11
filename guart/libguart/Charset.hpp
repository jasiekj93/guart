#pragma once

/**
 * @file Border.hpp
 * @author Adrian Szczepanski
 * @date 30-06-2025
 */

namespace guart
{
    namespace border
    {
        namespace bold
        {
            static constexpr auto TOP_LEFT = "╔";
            static constexpr auto TOP_RIGHT = "╗";
            static constexpr auto LOWER_LEFT = "╚";
            static constexpr auto LOWER_RIGHT = "╝";
            static constexpr auto HORIZONTAL = "═";
            static constexpr auto HORIZONTAL_UP = "╦";
            static constexpr auto HORIZONTAL_DOWN = "╩";
            static constexpr auto VERTICAL = "║";
            static constexpr auto VERTICAL_RIGHT = "╣";
            static constexpr auto VERTICAL_LEFT = "╠";
            static constexpr auto CROSS = "╬";
        }

        static constexpr auto TOP_LEFT = "┌";
        static constexpr auto TOP_RIGHT = "┐";
        static constexpr auto LOWER_LEFT = "└";
        static constexpr auto LOWER_RIGHT = "┘";
        static constexpr auto HORIZONTAL = "─";
        static constexpr auto HORIZONTAL_UP = "┬";
        static constexpr auto HORIZONTAL_DOWN = "┴";
        static constexpr auto VERTICAL = "│";
        static constexpr auto VERTICAL_RIGHT = "┤";
        static constexpr auto VERTICAL_LEFT = "├";
        static constexpr auto CROSS = "┼";
    }

    namespace style
    {
        static constexpr auto REVERSE = "\e[7m";
        static constexpr auto DIMMER = "\e[2m";
        static constexpr auto NORMAL = "\e[m";
        static constexpr auto BLINK = "\e[5m";
        static constexpr auto BLINK_OFF = "\e[25m";
    }

    static constexpr auto CHECK_BOX_CHECKED = "☒";
    static constexpr auto CHECK_BOX_UNCHECKED = "☐";
    static constexpr auto RADIO_BUTTON_CHECKED = "◉";
    static constexpr auto RADIO_BUTTON_UNCHECKED = "○";

    static constexpr auto WHITE_VERTICAL_RECTANGLE = "▯";
    static constexpr auto BLACK_VERTICAL_RECTANGLE = "█";
    static constexpr auto BLACK_UP_POINTING_TRIANGLE = "▲";
    static constexpr auto BLACK_DOWN_POINTING_TRIANGLE = "▼";
    static constexpr auto BLACK_LEFT_POINTING_TRIANGLE = "◀";
    static constexpr auto BLACK_RIGHT_POINTING_TRIANGLE = "▶";
    static constexpr auto BLACK_HORIZONTAL_RECTANGLE = "▬";
    static constexpr auto DARK_SHADE = "▓";
    static constexpr auto BLACK_CIRCLE = "●";
    static constexpr auto WARNING_SIGN = "⚠";
    static constexpr auto NO_ENTRY_SIGN = "⛔";
}
