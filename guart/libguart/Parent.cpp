#include "Parent.hpp"
#include "Widget.hpp"
#include <libguart/Key.hpp>

using namespace guart;

void Parent::addWidget(const std::shared_ptr<Widget>& child)
{
    if (not child)
        return;
    
    child->setParent(this);

    if(drawer)
        child->setDrawer(drawer);

    child->setFocusController(this);
    children.push_back(child);
}

void Parent::removeWidget(Widget* child)
{
    children.erase(std::remove_if(children.begin(), children.end(),
                                    [child](const std::shared_ptr<Widget>& w) { return w.get() == child; }),
                    children.end());

    invalidate();
}

void Parent::dispose()
{
    if(focusController)
        focusController->removeFocusable(this);

    while(not children.empty())
    {
        if(children.front())
            children.front()->dispose();
    }
}

void Parent::childFocusedCallback(Widget* child)
{
    if(not child)
        return;
    
    focusChangeCallback(true);

    auto it = std::find_if(children.begin(), children.end(),
                    [child](const std::shared_ptr<Widget>& w) { return w.get() == child; });

    if(it != children.end())
        std::rotate(it, it+1, children.end()); //move to the end, so it will be first on Z axis

    this->invalidate();
}

void Parent::invalidate() const
{
    Drawable::invalidate();

    for(auto& child : children)
    {
        if(child)
            child->invalidate();
    }
}

void Parent::setDrawer(Drawer* d)
{
    Drawable::setDrawer(d);

    for(auto& child : children)
    {
        if(child)
            child->setDrawer(d);
    }
}

void Parent::setActive(bool active)
{
    Drawable::setActive(active);

    if(isFocusable() and focusController)
    {
        if(active)
            focusController->addFocusable(this, false);
        else
            focusController->removeFocusable(this);
    }

    for(auto& widget : children)
    {
        if(widget)
            widget->setActive(active);
    }
}

void Parent::setFocusController(FocusController* controller)
{
    Focusable::setFocusController(controller);
}

void Parent::processKey(const std::string_view& input)
{
    if (input.empty() or focusables.empty())
        return;

    if (input == key::PAGE_DOWN)
        gotoNextFocusable();
    else if (input == key::PAGE_UP)
        gotoPreviousFocusable();
    else
        (*focused)->processKey(input);
}
