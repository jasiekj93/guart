#pragma once

/**
 * @file List.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <string>
#include <vector>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class List : public Widget
    {
    public:
        using Items = std::vector<std::string>;

        List(const Point&, const Dimensions&, const Items& items = {}, bool addBorder = false);

        void addItem(std::string_view);
        void setItems(const Items& items); 
        void setActiveIndex(int index);

        inline const Items& getItems() const { return items; }
        inline auto getDimensions() const { return dimensions; }
        inline auto getActiveIndex() const { return activeIndex; }
        inline auto getDisplayedIndex() const { return displayedIndex; }

        inline bool hasBorder() const { return addBorder; }
        inline void setBorder(bool border) { addBorder = border; }

        inline void setTitle(std::string_view l) { title = l; }
        inline std::string_view getTitle() const { return title; }

        inline virtual std::string_view getType() const override { return "List"; }
        inline bool isFocusable() const { return true; }

        virtual void processKey(const std::string_view&) override;

    protected:
        inline virtual void processActiveIndexChange() {}

    private:
        Dimensions dimensions;
        Items items;
        std::string title;
        int activeIndex = -1;
        int displayedIndex = 0;
        bool addBorder;
    };
} 