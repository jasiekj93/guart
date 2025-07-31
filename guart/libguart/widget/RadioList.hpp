#pragma once

/**
 * @file RadioList.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <etl/string.h>

#include <libguart/widget/List.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class RadioList : public List
    {
    public:
        RadioList(const Point&, const Dimensions&, const Items& items = {}, bool addBorder = false);

        void processKey(const etl::string_view&) override;

        etl::string_view getSelectedItem() const;
        inline auto getSelectedIndex() const { return selectedIndex; }

        inline virtual etl::string_view getType() const override { return "RadioList"; }

    private:
        int selectedIndex = -1; // Index of the currently selected item
    };
} 