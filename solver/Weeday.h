#ifndef WEEKDAY_H
#define WEEKDAY_H

#include <string>
#include <set>

namespace MyNamespace {

/**
 * @brief Класс, представляющий день недели.
 */
class Weekday {
public:
    /**
     * @brief константа для понедельника
     */
    static const Weekday Monday;

    /**
     * @brief константа для вторника
     */
    static const Weekday Tuesday;

    /**
     * @brief константа для среды
     */
    static const Weekday Wednesday;

    /**
     * @brief константа для четверга
     */
    static const Weekday Thursday;

    /**
     * @brief константа для пятницы
     */
    static const Weekday Friday;

    /**
     * @brief константа для субботы
     */
    static const Weekday Saturday;

    /**
     * @brief константа для воскресенья
     */
    static const Weekday Sunday;

    /**
     * @brief Множество, содержащее все дни недели.
     */
    static std::set<Weekday> WeekDays;

    /**
     * @brief Получает имя дня недели.
     * @return Имя дня недели.
     */
    Weekday(const std::wstring& name);

    /**
     * @brief Конструктор для создания объекта Weekday с указанным именем.
     * @param name Имя дня недели.
     */
    const std::wstring& getName() const;

    /**
     * @brief Оператор сравнения для Weekday.
     * @param other Другой объект Weekday для сравнения.
     * @return True, если данный Weekday меньше other, в противном случае false.
     */
    bool operator<(const Weekday& other) const;

private:
    std::wstring name;
};

}

#endif