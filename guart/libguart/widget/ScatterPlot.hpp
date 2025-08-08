#pragma once

/**
 * @file ScatterPlot.hpp
 * @author Adrian Szczepanski
 * @date 07-08-2025
 */

#include <string>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class ScatterPlot : public Widget
    {
    public:
        using Items = std::vector<Point>; 

        ScatterPlot(const Point& position, const Dimensions& size, bool startAtZero = false,
            std::string_view xTitle = {}, std::string_view yTitle = {}, 
            const Items& = {});

        inline auto& getDimensions() const { return dimensions; }

        inline void setTitle(const std::string_view& t) { title = t; }
        inline auto& getTitle() const { return title; }

        inline void setXTitle(const std::string_view& t) { xTitle = t; }
        inline auto& getXTitle() const { return xTitle; }

        inline void setYTitle(const std::string_view& t) { yTitle = t; }
        inline auto& getYTitle() const { return yTitle; }

        inline Items& getItems() { return items; }
        inline const Items& getItems() const { return items; }

        inline void addItem(const Point& p) { items.push_back(p); }
        inline void clearItems() { items.clear(); }
        inline void setItems(const Items& newItems) { items = newItems; }

        inline std::string_view getType() const override { return "ScatterPlot"; }

    private:
        Dimensions dimensions;
        bool startAtZero; 
        std::string title;
        std::string xTitle;
        std::string yTitle;
        Items items; 
    };
} 