#include "RadioList.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

RadioList::RadioList(const Point& p, const Dimensions& d, const Items &items, bool addBorder)
    : List(p, d, items, addBorder)
{
}

void RadioList::processKey(const etl::string_view &input)
{
    if(input.empty())
        return;

    List::processKey(input);

    if(input == key::SPACE)
    {
        auto activeIndex = getActiveIndex();

        if(selectedIndex == activeIndex)
            selectedIndex = -1; // Deselect if already selected
        else
            selectedIndex = activeIndex; 

        invalidate();
    }
}

etl::string_view guart::widget::RadioList::getSelectedItem() const
{
    if(selectedIndex == -1)
        return etl::string_view();
    else
        return getItems()[selectedIndex];
}
