#include "Date.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
namespace MyNamespace
{
Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
    if (!isValid())
        throw std::invalid_argument("Invalid date provided.");
}

Date::Date(int d, Month m, int y) : day(d), month(static_cast<int>(m)), year(y) 
{
    if (!isValid())
        throw std::invalid_argument("Invalid date provided.");
}

bool Date::isValid() const 
{
    if (day < 1 || day > daysInMonth(month, year))
        return false;
    if (month < 1 || month > 12)
        return false;
    return true;
}

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year)
{
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (isLeapYear(year))
              return 29;
            else
              return 28;
        default:
            return 31;
    }
}

int Date::daysInMonth(Month month, int year) 
{
    return daysInMonth(static_cast<int>(month), year);
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

bool Date::operator==(const Date &other) const 
{
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date &other) const
{
    return !(*this == other);
}

bool Date::operator<(const Date &other) const 
{
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::operator<=(const Date &other) const
{
    return *this < other || *this == other;
}

bool Date::operator>(const Date &other) const 
{
    return !(*this <= other);
}

bool Date::operator>=(const Date &other) const 
{
    return !(*this < other);
}

Date Date::operator+(int days) const 
{
    Date result = *this;
    while (days > 0) 
    {
        int daysLeftInMonth = daysInMonth(result.month, result.year) - result.day;
        if (days <= daysLeftInMonth) 
        {
            result.day += days;
            days = 0;
        } 
        else 
        {
            days -= (daysLeftInMonth + 1);
            result.day = 1;
            if (result.month == 12)
            {
                result.month = 1;
                ++result.year;
            } 
            else 
            {
                ++result.month;
            }
        }
    }
    return result;
}

Date Date::operator-(int days) const
{
    Date result = *this;
    while (days > 0)
      {
        if (days < result.day)
        {
            result.day -= days;
            days = 0;
        } else 
        {
            days -= result.day;
            if (result.month == 1) 
            {
                result.month = 12;
                --result.year;
            } 
            else 
            {
                --result.month;
            }
            result.day = daysInMonth(result.month, result.year);
        }
    }
    return result;
}

int Date::operator-(const Date &other) const 
{
    if (*this == other) return 0;

    Date start = *this < other ? *this : other;
    Date end = *this < other ? other : *this;

    int days = 0;
    while (start != end)
    {
      start = start + 1;
      days++;
    }

    return *this < other ? -days : days;
}

std::string Date::duration(const Date &other) const 
{
    int years = std::abs(year - other.year);
    int months = std::abs(month - other.month);
    int days = std::abs(day - other.day);

    std::string result;
    if (years > 0) 
      result += std::to_string(years) + " year" + (years > 1 ? "s " : " ");
    if (months > 0)
      result += std::to_string(months) + " month" + (months > 1 ? "s " : " ");
    if (days > 0) 
      result += std::to_string(days) + " day" + (days > 1 ? "s " : " ");

    return result;
}

Weekday Date::dayOfWeek() const 
{
  int CodMonth[12] {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };
  int CodMonth2[12]{0,3,4,0,2,5,0,3,6,1,4,6};
  int year = this->year;
  int month = static_cast<int>(this->month);
  int day = this->day;
  int index = 0;
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    index = ((day + CodMonth2[month-1] + 6 + year % 100 + (year % 100) / 4) % 7)-2;
  else
    index = ((day + CodMonth[month-1] + 6 + year % 100 + (year % 100)/ 4 ) % 7)-2;
  switch (index) {
        case 0: return Weekday::Sunday;
        case 1: return Weekday::Monday;
        case 2: return Weekday::Tuesday;
        case 3: return Weekday::Wednesday;
        case 4: return Weekday::Thursday;
        case 5: return Weekday::Friday;
        case 6: return Weekday::Saturday;
        default: throw std::runtime_error("Invalid day index computed.");
  }

}
std::string Date::weekDayToString(Weekday weekday)
{
    return std::string(weekday.getName().begin(), weekday.getName().end());
}

int Date::GetDay() const 
{
    return day;
}

int Date::GetMonth() const 
{
    return month;
}

int Date::GetYear() const 
{
    return year;
}

Date Date::Tomorrow() const 
{
    return *this + 1;
}

Date Date::Yesterday() const 
{
    return *this - 1;
}

Date Date::DayAfterTomorrow() const
{
    return *this + 2;
}

Date Date::DayBeforeYesterday() const
{
    return *this - 2;
}

}