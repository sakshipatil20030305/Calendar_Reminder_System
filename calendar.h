#ifndef CALENDAR_H
#define CALENDAR_H

void display_calendar(int month, int year);
int get_day_of_week(int day, int month, int year);
int is_valid_date(int day, int month, int year);
int is_leap_year(int year);

#endif
