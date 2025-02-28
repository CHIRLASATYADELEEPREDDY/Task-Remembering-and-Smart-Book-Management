#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure
struct Task {
 char description[100];
 int completed;
  };

// Book structure
struct Book {
char title[100];
char author[100];
  };

// Function to add a new task
void addTask(struct Task tasks[], int *taskCount, char description[]) {
 strcpy(tasks[*taskCount].description, description);
    tasks[*taskCount].completed = 0;
    (*taskCount)++;
    printf("Task added successfully!\n");
    }

// Function to mark a task as completed
void completeTask(struct Task tasks[], int taskCount, int taskNumber) {
    if (taskNumber >= 0 && taskNumber < taskCount) {
     tasks[taskNumber].completed = 1;
        printf("Task marked as completed!\n");
     } else {
        printf("Invalid task number!\n");
     }
     }

// Function to add a new book
void addBook(struct Book books[], int *bookCount, char title[], char author[]) {
    strcpy(books[*bookCount].title, title);
    strcpy(books[*bookCount].author, author);
    (*bookCount)++;
    printf("Book added successfully!\n");
   }

// Function to display tasks
void displayTasks(struct Task tasks[], int taskCount) {
    printf("Tasks:\n");
    for (int i = 0; i < taskCount; ++i) {
        printf("%d. [%s] %s\n", i, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
    }

// Function to display books
void displayBooks(struct Book books[], int bookCount) {
    printf("Books:\n");
    for (int i = 0; i < bookCount; ++i) {
        printf("%d. %s by %s\n", i, books[i].title, books[i].author);
    }
    }

int main() {
    struct Task tasks[100];
    struct Book books[100];
    int taskCount = 0;
    int bookCount = 0;
    int choice, taskNumber;
    char description[100];
    char title[100], author[100];

    while (1) {
        printf("\nTask and Book Management Menu:\n");
        printf("1. Add Task\n");
        printf("2. Complete Task\n");
        printf("3. Add Book\n");
        printf("4. Display Tasks\n");
        printf("5. Display Books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

  switch (choice) {
    case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                addTask(tasks, &taskCount, description);
                break;
   case 2:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &taskNumber);
                completeTask(tasks, taskCount, taskNumber);
                break;
   case 3:
                printf("Enter book title: ");
                scanf(" %[^\n]", title);
                printf("Enter book author: ");
                scanf(" %[^\n]", author);
                addBook(books, &bookCount, title, author);
                break;
     case 4:
                displayTasks(tasks, taskCount);
                break;
     case 5:
                displayBooks(books, bookCount);
                break;
      case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
