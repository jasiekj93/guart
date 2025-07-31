#pragma once

/**
 * @file CheckList.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <etl/string.h>
#include <etl/vector.h>

#include <libguart/widget/List.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class CheckList : public List
    {
    public:
        CheckList(const Point&, const Dimensions&, const Items& items = {}, bool addBorder = false);

        void processKey(const etl::string_view&) override;

        Items getSelectedItems() const;
        inline auto& getSelectedIndexes() const { return selectedIndexes; }

        inline virtual etl::string_view getType() const override { return "CheckList"; }

    private:
        etl::vector<int, ITEM_LIMIT> selectedIndexes;
    };
} 