#include <stdio.h>
#include <string.h>

#define MAX_TASKS 5
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int taskCount = 0;

int main() {
    int i;

    printf("Enter up to 5 tasks:\n");

    for (i = 0; i < MAX_TASKS; i++) {
        printf("Enter task %d: ", i + 1);
        fgets(tasks[i], MAX_LENGTH, stdin);

        // Remove newline character
        tasks[i][strcspn(tasks[i], "\n")] = '\0';

        taskCount++;
    }

    printf("\nTask List:\n");

    for (i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }

    return 0;
}
