#include "Parent.hpp"

using namespace guart;

void Parent::addWidget(const std::shared_ptr<Widget> widget)
{
    if (widget)
    {
        widget->setParent(this);
        widgets.push_back(widget);
    }
}

void Parent::invalidateWidgets() const
{
    for (const auto& widget : widgets)
    {
        if (widget)
            widget->invalidate();
    }
}