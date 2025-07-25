#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reminder.h"
#include "calendar.h"

Reminder reminders[MAX_REMINDERS];
int reminder_count = 0;

void load_reminders() {
    FILE *fp = fopen("reminders.txt", "r");
    if (!fp) return;

    while (fscanf(fp, "%d %d %d %[^\n]", &reminders[reminder_count].day,
                  &reminders[reminder_count].month,
                  &reminders[reminder_count].year,
                  reminders[reminder_count].note) == 4) {
        reminder_count++;
    }
    fclose(fp);
}

void save_reminders() {
    FILE *fp = fopen("reminders.txt", "w");
    if (!fp) {
        perror("Error saving reminders");
        return;
    }
    for (int i = 0; i < reminder_count; i++) {
        fprintf(fp, "%d %d %d %s\n", reminders[i].day,
                                     reminders[i].month,
                                     reminders[i].year,
                                     reminders[i].note);
    }
    fclose(fp);
}

void show_reminders() {
    if (reminder_count == 0) {
        printf("\n  No reminders found.\n");
        return;
    }

    printf("\n Your Reminders:\n");
    printf("---------------------------------------------------\n");
    printf("|   Date       |  Note                             |\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < reminder_count; i++) {
        printf("| %02d-%02d-%04d | %-32s |\n", reminders[i].day,
                                                reminders[i].month,
                                                reminders[i].year,
                                                reminders[i].note);
    }
    printf("---------------------------------------------------\n");
}

void add_reminder() {
    if (reminder_count >= MAX_REMINDERS) {
        printf(" Reminder list full!\n");
        return;
    }

    Reminder r;
    printf("Enter date (DD MM YYYY): ");
    if (scanf("%d %d %d", &r.day, &r.month, &r.year) != 3 || !is_valid_date(r.day, r.month, r.year)) {
        printf(" Invalid date! Please enter a valid date.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    getchar(); // clear newline after date input
    printf("Enter note: ");
    fgets(r.note, sizeof(r.note), stdin);
    r.note[strcspn(r.note, "\n")] = '\0'; // remove newline

    reminders[reminder_count++] = r;
    save_reminders();
    printf("Reminder added successfully!\n");
}
void edit_reminder() {
    if (reminder_count == 0) {
        printf(" No reminders to edit.\n");
        return;
    }

    printf("\n Select a reminder to edit:\n");
    for (int i = 0; i < reminder_count; i++) {
        printf("%d. %02d-%02d-%04d - %s\n", i + 1,
               reminders[i].day, reminders[i].month, reminders[i].year,
               reminders[i].note);
    }

    int choice;
    printf("Enter reminder number to edit: ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > reminder_count) {
        printf(" Invalid choice.\n");
        while (getchar() != '\n');
        return;
    }

    Reminder *r = &reminders[choice - 1];
    printf("📅 Enter new date (DD MM YYYY): ");
    if (scanf("%d %d %d", &r->day, &r->month, &r->year) != 3 || !is_valid_date(r->day, r->month, r->year)) {
        printf(" Invalid date! Edit cancelled.\n");
        while (getchar() != '\n');
        return;
    }

    getchar(); // clear newline
    printf("📝 Enter new note: ");
    fgets(r->note, sizeof(r->note), stdin);
    r->note[strcspn(r->note, "\n")] = '\0';

    save_reminders();
    printf("Reminder updated successfully!\n");
}

void delete_reminder() {
    if (reminder_count == 0) {
        printf(" No reminders to delete.\n");
        return;
    }

    printf("\nSelect a reminder to delete:\n");
    for (int i = 0; i < reminder_count; i++) {
        printf("%d. %02d-%02d-%04d - %s\n", i + 1,
               reminders[i].day, reminders[i].month, reminders[i].year,
               reminders[i].note);
    }

    int choice;
    printf("Enter reminder number to delete: ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > reminder_count) {
        printf(" Invalid choice.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    for (int i = choice - 1; i < reminder_count - 1; i++) {
        reminders[i] = reminders[i + 1];  // shift
    }
    reminder_count--;

    save_reminders();
    printf(" Reminder deleted successfully.\n");
}


