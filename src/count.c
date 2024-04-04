#include "count.h"

// Проверка на високосный год
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Возвращает количество дней в заданном месяце
int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Функция, которая считает количество дней между двумя датами
int days_between_dates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;

    // Добавляем количество дней для каждого года между годами 1 и 2
    for (int year = year1; year < year2; ++year) {
        days += is_leap_year(year) ? 366 : 365;
    }

    // Добавляем количество дней для каждого месяца между месяцами 1 и 2 в году year1
    for (int month = month1; month <= 12; ++month) {
        days += days_in_month(month, year1) - day1 + 1;
        day1 = 0; // Теперь для оставшихся месяцев в этом году первый день будет 1
    }

    // Добавляем количество дней для каждого месяца между месяцами 1 и 2 в году year2
    for (int month = 1; month < month2; ++month) {
        days += days_in_month(month, year2);
    }

    // Добавляем оставшиеся дни между днями 1 и 2 в году year2
    days += day2 - 1;

    return days;
}

