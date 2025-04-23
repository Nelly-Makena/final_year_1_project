#include <stdio.h>

// Functions
void add_task();
void list_tasks();
void mark_done();
void delete_task();

int main() {
    int choice;
    do {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Mark Task as Done\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_task(); break;
            case 2: list_tasks(); break;
            case 3: mark_done(); break;
            case 4: delete_task(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task description: ");
    getchar();
    fgets(tasks[task_count].description, MAX_LENGTH, stdin);
    tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = 0; // Remove newline
    tasks[task_count].completed = 0;
    task_count++;
    printf("Task added successfully!\n");
}

void list_tasks() {
    // To be implemented by Scott 
}

void mark_done() {
    // To be implemented by Erastus
}

void delete_task() {
    // To be implemented by Erastus
}
