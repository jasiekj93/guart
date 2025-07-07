#pragma once

/**
 * @file Screen.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <memory>
#include <vector>
#include <map>

#include <libguart/Output.hpp>
#include <libguart/Canvas.hpp>
#include <libguart/Widget.hpp>

namespace guart
{
    class Screen : public Canvas, public Drawer 
    {
    public:
        explicit Screen(Output&); 

        void addWidget(const std::shared_ptr<Widget>&);
        void invalidate() const;

        //Canvas
        void moveCursor(const Point& p) const override;
        inline Output& getOutput() const override { return output; }
        void clear() const override;

        //Drawer
        void draw(const Widget& widget) const override;

        bool processInput(const std::string_view&);

    protected:
        void changeFocus();

    private:
        Output& output;
        std::vector<std::shared_ptr<Widget>> widgets;
        std::map<std::string_view, std::unique_ptr<Drawer>> drawers;
        int focusedIndex = -1;
    };
}