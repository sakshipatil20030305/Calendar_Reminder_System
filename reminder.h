#ifndef REMINDER_H
#define REMINDER_H

#define MAX_REMINDERS 100

typedef struct {
    int day;
    int month;
    int year;
    char note[100];
} Reminder;

void load_reminders();
void save_reminders();
void show_reminders();
void add_reminder();
void edit_reminder();
void delete_reminder();  // 🆕 Add this line



#endif
