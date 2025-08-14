#pragma once

/**
 * @file BarGraph.hpp
 * @author Adrian Szczepanski
 * @date 12-08-2025
 */

#include <string>
#include <map>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class BarGraph : public Widget
    {
    public:
        using Item = std::pair<std::string, unsigned int>;
        using Items = std::vector<Item>;

        BarGraph(const Point& position, const Dimensions& size, bool startAtZero = false,
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

        inline void addItem(const Item& item) { items.push_back(item); }
        inline void clearItems() { items.clear(); }
        inline void setItems(const Items& newItems) { items = newItems; }

        inline std::string_view getType() const override { return "BarGraph"; }

    private:
        Dimensions dimensions;
        bool startAtZero; 
        std::string title;
        std::string xTitle;
        std::string yTitle;
        Items items; 
    };
} 