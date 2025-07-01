#pragma once

/**
 * @file Screen.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <memory>
#include <vector>

#include <libguart/Parent.hpp>
#include <libguart/Output.hpp>

namespace guart
{
    class Screen : public Parent
    {
    public:
        explicit Screen(Output&); 

        void invalidate() const;

        void moveCursor(const Point& p) const override;
        inline Output& getOutput() const override { return output; }

        void clean() const;

    private:
        Output& output;
    };
}