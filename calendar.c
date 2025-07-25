#include <stdio.h>
#include "calendar.h"

const char *months[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const int days_in_month[] = {
    0, 31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_day_of_week(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int h = (day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    // Zeller's Congruence gives: 0=Saturday, 1=Sunday, ..., 6=Friday
    // Convert it to: 0=Sunday, 1=Monday, ..., 6=Saturday
    int day_of_week = (h + 6) % 7;

    return day_of_week;
}


int is_valid_date(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return 0;
    int max_day = days_in_month[month];
    if (month == 2 && is_leap_year(year))
        max_day = 29;
    return day <= max_day;
}

void display_calendar(int month, int year) {
    int days = days_in_month[month];
    if (month == 2 && is_leap_year(year))
        days = 29;

    int start_day = get_day_of_week(1, month, year); // Sunday = 0

    printf("\n  -----------------------------\n");
    printf("         %s %d\n", months[month], year);
    printf("  -----------------------------\n");
    printf("  Su Mo Tu We Th Fr Sa\n");

    for (int i = 0; i < start_day; i++)
        printf("   ");

    for (int day = 1; day <= days; day++) {
        printf("%3d", day);
        if ((start_day + day) % 7 == 0 || day == days)
            printf("\n");
    }
    printf("\n");
}
