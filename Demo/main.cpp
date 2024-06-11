#include "..\solver\Date.h"
#include <iostream>

int main() 
{
    Date d1(11, 6, 2024);
    Date d2(1, Month::January, 2025);

    std::cout << "Дата 1: " << d1 << std::endl;
    std::cout << "Дата 2: " << d2 << std::endl;

    std::cout  << d1.duration(d2) << std::endl;
    std::cout <<  Date::weekDayToString(d1.dayOfWeek()) << std::endl;
    std::cout <<  Date::weekDayToString(d2.dayOfWeek())<< std::endl;

    std::cout << d1.Tomorrow() << std::endl;
    std::cout << d1.Yesterday() << std::endl;
    std::cout << d1.DayAfterTomorrow()<< std::endl;
    std::cout << d1.DayBeforeYesterday()<< std::endl;
    
  return 0;
}
