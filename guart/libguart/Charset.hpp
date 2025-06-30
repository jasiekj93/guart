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

    static constexpr auto CHECK_BOX = "☑";
    static constexpr auto CHECK_BOX_UNCHECKED = "☐";

}
