class Task:
    def __init__(self, title):
        self.title = title
        self.isDone = False

    def markDone(self):
        self.isDone = True

    def display(self):
        if self.isDone:
            print(self.title + " - DONE")
        else:
            print(self.title + " - PENDING")


class TaskList:
    def __init__(self):
        self.tasks = []

    def addTask(self, title):
        self.tasks.append(Task(title))

    def markTaskDone(self, index):
        if 0 <= index < len(self.tasks):
            self.tasks[index].markDone()

    def showTasks(self):
        for i, task in enumerate(self.tasks):
            print(f"{i + 1}. ", end="")
            task.display()


# Demonstration
taskList = TaskList()

taskList.addTask("Complete assignment")
taskList.addTask("Study Python")
taskList.addTask("Practice programming")

# Mark second task as done
taskList.markTaskDone(1)

print("Task List:")
taskList.showTasks()
