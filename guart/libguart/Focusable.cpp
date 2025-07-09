#include "Focusable.hpp"

using namespace guart;

Focusable::~Focusable()
{
    if(isFocusable() and focusController)
        focusController->removeFocusable(this);
}

void Focusable::setFocusController(FocusController *controller)
{
    if(not controller)
        return;

    focusController = controller;

    if(isFocusable())
        controller->addFocusable(this);
}

bool Focusable::isFocused() const
{
    if(not focusController)
        return false;
    else
        return focusController->isFocused(this);
}