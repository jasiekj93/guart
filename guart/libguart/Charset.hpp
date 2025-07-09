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

    namespace control
    {
        static constexpr auto REVERSE_ON = "\e[7m";
        static constexpr auto REVERSE_OFF = "\e[m";
    }

    static constexpr auto CHECK_BOX = "☑";
    static constexpr auto CHECK_BOX_UNCHECKED = "☐";

    static constexpr auto WHITE_VERTICAL_RECTANGLE = "▯";
    static constexpr auto BLACK_VERTICAL_RECTANGLE = "▮";
    static constexpr auto BLACK_UP_POINTING_TRIANGLE = "▲";
    static constexpr auto BLACK_DOWN_POINTING_TRIANGLE = "▼";

}
