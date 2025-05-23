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
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nTask List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
    }


void mark_done() {
    int index;
    printf("Enter task number to mark as done: ");
    scanf("%d", &index);
    if (index < 1 || index > task_count) {
        printf("Invalid task number!\n");
        return;
    }
    tasks[index - 1].completed = 1;
    printf("Task marked as done!\n");
}
void delete_task() {
    int index;
    printf("Enter task number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > task_count) {
        printf("Invalid task number!\n");
        return;
    }
    for (int i = index - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
    printf("Task deleted successfully!\n");
}