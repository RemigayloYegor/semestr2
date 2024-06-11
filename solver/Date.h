#include <iostream>
#include <string>

/*
*@brief Класс для работы с Месяцами
*/
enum class Month
{
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

/*
*@brief Класс для работы с днями неделями
*/
enum class Weekday 
{
Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

class Date {
private:
    int day; // День
    int month; // Месяц
    int year; // Год
public:
    Date(int d, int m, int y); // конструктор
    Date(int d, Month m, int y); // конструктор

    ~Date();  // Деструктор
    Date(const Date& other);  // Конструктор копирования
    Date& operator=(const Date& other);  // Оператор присваивания копированием
    Date(Date&& other) noexcept;  // Конструктор перемещения
    Date& operator=(Date&& other) noexcept;  // Оператор присваивания перемещением

    bool isValid() const; // Проверка корректности даты
    static bool isLeapYear(int year); //Вычисление високосности года
    static int daysInMonth(int month, int year); //Вычисление количества дней в месяце
    static int daysInMonth(Month month, int year); //Вычисление количества дней в месяце

    int GetDay() const;    // Получить день
    int GetMonth() const;  // Получить месяц
    int GetYear() const;   // Получить год

    friend std::ostream &operator<<(std::ostream &os, const Date &date);  // Оператор вывода
    bool operator==(const Date &other) const;  // Оператор сравнения ==
    bool operator!=(const Date &other) const;  // Оператор сравнения !=
    bool operator<(const Date &other) const;  // Оператор сравнения <
    bool operator<=(const Date &other) const;  // Оператор сравнения <=
    bool operator>(const Date &other) const;  // Оператор сравнения >
    bool operator>=(const Date &other) const;  // Оператор сравнения >=
    Date operator+(int days) const;  // Оператор сложения с днем
    Date operator-(int days) const;  // Оператор вычитания с днем
    int operator-(const Date &other) const;  // Оператор вычитания двух дат
    static std::string weekDayToString(Weekday weekday);  // Преобразование дня недели в строку

    std::string duration(const Date &other) const;  // Вычисление продолжительности между двумя дат
    Weekday dayOfWeek() const;  // Вычисление дня недели

    Date Tomorrow() const;  // Получить дату следующего дня
    Date Yesterday() const;  // Получить дату предыдущего дня
    Date DayAfterTomorrow() const;  // Получить дату следующего дня после следующего
    Date DayBeforeYesterday() const;  // Получить дату предыдущего дня до предыдущего
};
