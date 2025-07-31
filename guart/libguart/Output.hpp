#pragma once

/**
 * @file Output.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <etl/string.h>

namespace guart
{
    class Output
    {
    public:
        virtual ~Output() = default;

        virtual Output& operator<<(const etl::string_view) = 0;
        virtual Output& operator<<(char) = 0;

        virtual void flush() {}
    };
}