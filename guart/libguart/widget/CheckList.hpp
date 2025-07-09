#pragma once

/**
 * @file CheckList.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <string>
#include <vector>

#include <libguart/widget/List.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class CheckList : public List
    {
    public:
        CheckList(const Point&, const Dimensions&, const Items& items = {}, bool addBorder = false);

        void processKey(const std::string_view&) override;

        Items getSelectedItems() const;
        inline auto& getSelectedIndexes() const { return selectedIndexes; }

        inline virtual std::string_view getType() const override { return "CheckList"; }

    private:
        std::vector<int> selectedIndexes; 
    };
} 