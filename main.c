// main.c
#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "reminder.h"

void show_menu() {
    printf("\n=====================================================\n");
    printf("           📅 Calendar & Reminder System\n");
    printf("======================================================\n");
    printf("            1. 📆 Show Calendar\n");
    printf("            2. 📌 Show Reminders\n");
    printf("            3. ➕ Add Reminder\n");
    printf("            4. ✏️ Edit Reminder\n");
    printf("            5. ❌ Delete Reminder\n");
    printf("            6. 🚪 Exit\n");
    printf("=======================================================\n");
    printf("           Enter your choice: ");
}

void delete_reminder();  // Ensure function is declared

int main() {
    int choice, month, year;
    load_reminders();

    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter month and year (MM YYYY): ");
                if (scanf("%d %d", &month, &year) != 2 || month < 1 || month > 12 || year < 1) {
                    printf("❌ Invalid month/year!\n");
                    while (getchar() != '\n');
                    continue;
                }
                display_calendar(month, year);
                break;
            case 2:
                show_reminders();
                break;
            case 3:
                add_reminder();
                break;
            case 4:
                edit_reminder();
                break;
            case 5:
                delete_reminder();
                break;
            case 6:
                printf("Thank You... Have a great day!\n");
                exit(0);
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
