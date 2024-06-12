#include <iostream>
#include <string>
#include "Weekday.h"
#include "Month.h"
namespace MyNamespace
{
/**
* @brief Класс, представляющий календарную дату.
*/
class Date {
private:
    int day;
    int month;
    int year;

    /**
     * @brief Проверка корректности даты
     * @return Истинно, если дата действительна, в противном случае ложно.
     */
    bool isValid() const;
    /**
     * @brief Вычисление високосности года
     * @param год, который нужно проверить.
     * @return Истинно, если год является високосным, в противном случае ложно.
     */
    static bool isLeapYear(int year);
    /**
     * @brief Вычисление количества дней в месяце
     * @param Год
     * @return Количество дней в месяце
     */
    static int daysInMonth(int month, int year);
    /**
     * @brief Создает объект
     * @param Месяц
     * @param Год
     * @return Количество дней в месяце.
     */
    static int daysInMonth(Month month, int year);
public:
    /**
     * @brief Создает консруктор по умолчанию
     * @param День
     * @param Месяц
     * @param Год
     */
    Date(int d, int m, int y);
    /**
     * @brief Создает консруктор по умолчанию
     * @param День
     * @param Месяц
     * @param Год
     */
    Date(int d, Month m, int y);
    /**
     * @brief Получает день
     * @return день
     */
    int GetDay() const;
    /**
     * @brief Получает месяц
     * @return Месяц
     */
    int GetMonth() const;
    /**
     * @brief Получает год
     * @return год
     */
    int GetYear() const;

    /*
    *@brief оператор "<<" для класса Date
    */
    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    /*
    *@brief оператор "==" для класса Date
    */
    bool operator==(const Date &other) const;
    /*
    *@brief оператор "!=" для класса Date
    */
    bool operator!=(const Date &other) const;
    /*
    *@brief оператор "<" для класса Date
    */
    bool operator<(const Date &other) const;
    /*
    *@brief оператор "<=" для класса Date
    */
    bool operator<=(const Date &other) const;
    /*
    *@brief оператор ">" для класса Date
    */
    bool operator>(const Date &other) const;
    /*
    *@brief оператор ">=" для класса Date
    */
    bool operator>=(const Date &other) const;
    /*
    *@brief оператор "+" для класса Date
    */
    Date operator+(int days) const;
    /*
    *@brief оператор "-" для класса Date
    */
    Date operator-(int days) const;
    /*
    *@brief оператор "-" для класса Date
    */
    int operator-(const Date &other) const;
    /**
     * @brief Преобразует Weekday в строку.
     * @param weekday День недели в виде Weekday.
     * @return Строковое представление дня недели.
     */
    static std::string weekDayToString(Weekday weekday);
    /**
     * @brief Возвращает продолжительность между двумя датами.
     * @param other Другая дата.
     * @return Строка, представляющая продолжительность.
     */
    std::string duration(const Date &other) const;
    /**
     * @brief Возвращает день недели для текущей даты.
     * @return День недели в виде Weekday.
     */
    Weekday dayOfWeek() const;
    /**
     * @brief Возвращает дату завтрашнего дня.
     * @return Дата завтрашнего дня.
     */
    Date Tomorrow() const;
    /**
     * @brief Gets the date of yesterday.
     * @return The date of yesterday.
     */
    Date Yesterday() const;
    /**
     * @brief Возвращает дату послезавтрашнего дня.
     * @return Послезавтрашнее число.
     */
    Date DayAfterTomorrow() const;
    /**
     * @brief Возвращает дату позавчерашнего дн
     * @return Позавчерашняя дата.
     */
    Date DayBeforeYesterday() const;
};
}
