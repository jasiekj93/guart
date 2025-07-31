#pragma once

/**
 * @file List.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#ifndef GUART_WIDGET_LIST_ITEM_LENGTH_LIMIT
#define GUART_WIDGET_LIST_ITEM_LENGTH_LIMIT 32
#endif

#ifndef GUART_WIDGET_LIST_TITLE_LIMIT
#define GUART_WIDGET_LIST_TITLE_LIMIT 16
#endif

#ifndef GUART_WIDGET_LIST_ITEM_LIMIT
#define GUART_WIDGET_LIST_ITEM_LIMIT 32
#endif

#include <etl/string.h>
#include <etl/vector.h>

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class List : public Widget
    {
    public:
        static constexpr size_t TITLE_LIMIT = GUART_WIDGET_LIST_TITLE_LIMIT;
        static constexpr size_t ITEM_LENGTH_LIMIT = GUART_WIDGET_LIST_ITEM_LENGTH_LIMIT;
        static constexpr size_t ITEM_LIMIT = GUART_WIDGET_LIST_ITEM_LIMIT;

        using Item = etl::string<ITEM_LENGTH_LIMIT>;
        using Items = etl::vector<Item, ITEM_LIMIT>;

        List(const Point&, const Dimensions&, const Items& items = {}, bool addBorder = false);

        void addItem(etl::string_view);
        void setItems(const Items& items); 
        void setActiveIndex(int index);

        inline const Items& getItems() const { return items; }
        inline auto getDimensions() const { return dimensions; }
        inline auto getActiveIndex() const { return activeIndex; }
        inline auto getDisplayedIndex() const { return displayedIndex; }
        inline bool hasBorder() const { return addBorder; }

        inline void setTitle(etl::string_view l) { title = l; }
        inline etl::string_view getTitle() const { return title; }

        inline virtual etl::string_view getType() const override { return "List"; }
        inline bool isFocusable() const { return true; }

        virtual void processKey(const etl::string_view&) override;

    protected:
        inline virtual void processActiveIndexChange() {}

    private:
        Dimensions dimensions;
        Items items;
        etl::string<TITLE_LIMIT> title;
        int activeIndex = -1;
        int displayedIndex = 0;
        bool addBorder;
    };
} 