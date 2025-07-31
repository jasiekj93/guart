#pragma once

/**
 * @file CheckList.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <libguart/drawer/List.hpp>

namespace guart::drawer 
{
    class CheckList : public List 
    {
    public:
        explicit CheckList(Canvas& canvas);

    protected:
        void drawItem(const Drawable&, Output&, etl::string_view item, int index) const override;
    };

} 