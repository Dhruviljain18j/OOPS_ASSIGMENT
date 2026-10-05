#include <stdio.h>
#include <string.h>

#define MAX_TASKS 5
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int status[MAX_TASKS] = {0};  // 0 = not done, 1 = done
int taskCount = 0;

void markTaskDone(int index) {
    if (index >= 0 && index < taskCount) {
        status[index] = 1;
    }
}

int main() {
    int i;
    int doneIndex;

    printf("Enter up to 5 tasks:\n");

    for (i = 0; i < MAX_TASKS; i++) {
        printf("Enter task %d: ", i + 1);
        fgets(tasks[i], MAX_LENGTH, stdin);

        tasks[i][strcspn(tasks[i], "\n")] = '\0';

        taskCount++;
    }

    printf("\nWhich task do you want to mark as done? ");
    scanf("%d", &doneIndex);

    // User enters 1-5, array uses 0-4
    markTaskDone(doneIndex - 1);

    printf("\nUpdated Task List:\n");

    for (i = 0; i < taskCount; i++) {
        if (status[i])
            printf("%d. %s - DONE\n", i + 1, tasks[i]);
        else
            printf("%d. %s - PENDING\n", i + 1, tasks[i]);
    }

    return 0;
}
