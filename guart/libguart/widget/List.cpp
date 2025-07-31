#include "List.hpp"
#include <libguart/Key.hpp>

using namespace guart;
using namespace guart::widget;

List::List(const Point& p, const Dimensions& d, const Items& items, bool addBorder)
    : Widget(p)
    , dimensions(d)
    , addBorder(addBorder)
{
    setItems(items);
}

void List::addItem(etl::string_view item)
{
    items.push_back(Item(item));

    if(items.size() == 1)
        activeIndex = 0;
}

void List::setItems(const Items& items)
{
    this->items = items;

    if(not items.empty())
        activeIndex = 0;
}

void List::setActiveIndex(int index)
{
    if(index >= 0 and index < items.size())
        activeIndex = index;
}

void List::processKey(const etl::string_view& input)
{
    if(input.empty())
        return;
    
    if(input == key::UP)
    {
        if(activeIndex > 0)
        {
            --activeIndex;

            if(activeIndex < displayedIndex)
                displayedIndex = activeIndex;

            processActiveIndexChange();
            invalidate();
        }
    }
    else if(input == key::DOWN)
    {
        if(activeIndex < static_cast<int>(items.size()) - 1)
        {
            ++activeIndex;

            if(activeIndex >= dimensions.height)
                displayedIndex = activeIndex - dimensions.height + 1;

            processActiveIndexChange();
            invalidate();
        }
    }
    else if(input == key::CR or 
            input == key::CR_NL or 
            input == key::NEW_LINE) 
    {
        if(onAction)
            onAction(*this, items[activeIndex]);
    }

}
