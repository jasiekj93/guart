#pragma once

/**
 * @file List.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <libguart/drawer/Base.hpp>

namespace guart::drawer 
{
    class List : public Base 
    {
    public:
        explicit List(Canvas& canvas);

    protected:
        void drawWidget(const Drawable&, Canvas&) const override;
        virtual void drawItem(const Drawable&, Output&, std::string_view item, int index) const;
    };

} 