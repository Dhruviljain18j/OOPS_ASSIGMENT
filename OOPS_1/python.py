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
