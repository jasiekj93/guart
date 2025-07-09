#include "CheckList.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

CheckList::CheckList(const Point& p, const Dimensions& d, const Items &items, bool addBorder)
    : List(p, d, items, addBorder)
{
}

void CheckList::processKey(const std::string_view &input)
{
    if(input.empty())
        return;

    List::processKey(input);

    if(input == key::SPACE)
    {
        auto activeIndex = getActiveIndex();

        auto it = std::find(selectedIndexes.begin(), selectedIndexes.end(), activeIndex);

        if(it != selectedIndexes.end())
            selectedIndexes.erase(it); // Deselect if already selected
        else
        {
            selectedIndexes.push_back(activeIndex);
            std::sort(selectedIndexes.begin(), selectedIndexes.end());
        }

        invalidate();
    }
}

CheckList::Items guart::widget::CheckList::getSelectedItems() const
{
    Items selectedItems;

    for (auto index : selectedIndexes)
        selectedItems.push_back(getItems()[index]);

    return selectedItems;
}
