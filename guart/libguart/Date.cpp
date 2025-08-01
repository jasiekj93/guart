#include "Date.hpp"

using namespace guart;

const Date Date::DEFAULT_DATE = Date(1970, 1, 1); 

Date::Date()
    : year(DEFAULT_DATE.year), month(DEFAULT_DATE.month), day(DEFAULT_DATE.day)
{
}

Date::Date(Year y)
{
    if(y < DEFAULT_DATE.year)
        year = DEFAULT_DATE.year;
    else
        year = y;
}

Date::Date(Year y, Month m)
    : Date(y)
{
    if(m < 1 or m > 12)
        month = DEFAULT_DATE.month;
    else
        month = m;
}

Date::Date(Year y, Month m, Day d)
    : Date(y, m)
{
    day = d;
    normalizeDate();
}

Date::Date(std::string_view str)
{
    if(str.size() != 10 || str[4] != '-' || str[7] != '-')
    {
        year = DEFAULT_DATE.year;
        month = DEFAULT_DATE.month;
        day = DEFAULT_DATE.day;
        return;
    }

    year = std::stoi(std::string(str.substr(0, 4)));
    month = std::stoi(std::string(str.substr(5, 2)));
    day = std::stoi(std::string(str.substr(8, 2)));

    normalizeDate();
}

Date& Date::operator+=(const DateSpan& span)
{
    year += span.years;
    month += span.months;
    day += span.days;

    normalizeDate();
    return *this;
}

Date& guart::Date::operator-=(const DateSpan& span)
{
    year -= span.years;
    month -= span.months;
    day -= span.days;

    normalizeDate();
    return *this;
}

bool guart::Date::operator==(const Date& other) const
{
    return (year == other.year and 
        month == other.month and 
        day == other.day);
}

std::string Date::toString() const
{
    return std::to_string(year) + "-" +
           (month < 10 ? "0" : "") + std::to_string(month) + "-" +
           (day < 10 ? "0" : "") + std::to_string(day);
}

void Date::normalizeDate()
{
    normalizeDay();
    normalizeMonth();
}

void Date::normalizeDay()
{
    if(day < 1)
    {
        month--;
        day = getDaysInMonth(month, year) + day;
    }

    if(month == 2)
    {
        if(isLeapYear(year) and (day > 29))
        {
                day = day - 29;
                month++;
        }
        else if(not isLeapYear(year) and (day > 28))
        {
            day = day - 28;
            month++;
        }
    }
    else if((month == 4 or month == 6 or month == 9 or month == 11) and (day > 30))
    {
        day = day - 30;
        month++;
    }
    else if(day > 31)
    {
        day = day - 31;
        month++;
    }
}

void Date::normalizeMonth()
{
    if(month > 12)
    {
        month = 1;
        year++;
    }
    else if(month < 1)
    {
        month = 12;
        year--;
    }
}


bool guart::isLeapYear(Year year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            return false;
        }
        return true;
    }
    return false;
}

int guart::getWeekday(const Date &date)
{
    int y = date.getYear();
    int m = date.getMonth();
    int d = date.getDay();

    if (m < 3)
    {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;

    int weekday = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;

    weekday = (weekday < 0 ? weekday + 7 : weekday); 
    
    if(weekday == 0)
        return 6;
    else if(weekday == 1)
        return 7;
    else
        return weekday - 1; 
}

int guart::getDaysInMonth(Month month, Year year)
{
    if (month == 2)
    {
        return (isLeapYear(year) ? 29 : 28);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    return 31;
}

std::string guart::getMonthName(Month month)
{
    static const std::string monthNames[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    if (month < 1 || month > 12)
        return "";
    else
        return monthNames[month - 1];
}
