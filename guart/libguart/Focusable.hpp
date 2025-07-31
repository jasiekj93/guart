#pragma once

/**
 * @file Focusable.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <libguart/FocusController.hpp>

namespace guart
{
    class Focusable
    {
    public:
        virtual ~Focusable();

        virtual void setFocusController(FocusController*); 
        virtual bool isFocused() const;

        virtual inline bool isFocusable() const { return false; }
        virtual inline bool isModal() const { return false; }    

        virtual void processKey(const etl::string_view&) {}

        virtual void focusChangeCallback(bool isFocused) = 0;

    protected:
        FocusController* focusController = nullptr;
    };
}