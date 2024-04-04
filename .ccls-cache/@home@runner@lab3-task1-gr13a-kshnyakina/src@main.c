/* main.c */
#include <stdio.h>
#include "count.h"

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    printf("Введите первую дату в формате ДД ММ ГГГГ: ");
    scanf("%d %d %d", &day1, &month1, &year1);

    printf("Введите вторую дату в формате ДД ММ ГГГГ: ");
    scanf("%d %d %d", &day2, &month2, &year2);

    int days = days_between_dates(day1, month1, year1, day2, month2, year2);
    printf("Между этими датами прошло %d дней.\n", days);

    return 0;
}
