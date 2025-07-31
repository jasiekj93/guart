#include "Calendar.hpp"

#include <etl/to_string.h>

#include <libguart/widget/Calendar.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

Calendar::Calendar(Canvas& canvas)
    : Base(canvas)
{
}

void Calendar::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& calendar = static_cast<const widget::Calendar&>(drawable);
    auto& out = canvas.getOutput();

    drawBorder(calendar.getPosition(), Dimensions{ 29, 15 }); 

    Date::String dateString = getMonthName(calendar.getDate().getMonth()); 
    dateString += " ";
    etl::to_string(calendar.getDate().getYear(), dateString, true); 

    canvas.moveCursor(calendar.getPosition() + Point{ 2, 2 }); 
    out << dateString;

    canvas.moveCursor(calendar.getPosition() + Point{ 2, 3 }); 
    out << "Mon Tue Wed Thu Fri Sat Sun";
    
    auto week = 1;
    auto month = calendar.getDate().getMonth();
    auto year = calendar.getDate().getYear();

    for(auto i = 1; i <= getDaysInMonth(month, year); ++i)
    {
        auto weekDay = getWeekday(Date{ year, month, i });
        moveToWeekday(canvas, calendar.getPosition(), weekDay, week);
        
        if(i == calendar.getDate().getDay() and calendar.isFocused())
            out << style::REVERSE; // Highlight current day

        etl::string<3> dayString;
        
        out << (i < 10 ? " " : "");
        out << etl::to_string(i, dayString); 
        out.flush();

        if(i == calendar.getDate().getDay() and calendar.isFocused())
            out << style::NORMAL; // Highlight current day

        if(weekDay == 7) // If it's Sunday, move to next line
            week++;
    }
}

void Calendar::moveToWeekday(Canvas &canvas, const Point& top, int weekDay, int week) const
{
    weekDay--;
    week--;
    auto point = top + Point{ (Point::X)(3 + (weekDay * 4)), (Point::Y)(5 + (week * 2)) };

    canvas.moveCursor(point);
}
