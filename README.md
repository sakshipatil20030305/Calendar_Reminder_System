# Calendar_Reminder_System
I'm excited to share my latest project—a simple but powerful Calendar &amp; Reminder System built entirely in C
A **command-line** calendar and reminder manager built with pure C, featuring persistent storage and intuitive date management.

 Features

- Dynamic Calendar Generation
  - View any month/year (1900-9999)
  - Leap year detection
- Smart Reminder System
  - Add/edit/delete reminders
  - Auto-save to `reminders.txt`
  - Input validation (e.g., blocks "Feb 30")
- User-Friendly CLI
  - Color-coded menus (optional)
  - Helpful error messages
 Technical Stack

| Component       | Implementation Details |
|----------------|-----------------------|
| **Language**   | C99 (no external dependencies) |
| **Data Structure** | Array of `Reminder` structs |
| **Storage**    | Plaintext file (DD MM YYYY Note) |
| **Algorithms** | Zeller's Congruence, Leap year calc |
## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Linux/Windows terminal
