class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class TaskManager:
    def __init__(self):
        self.head = None

    def add_task(self, task):
        new_node = Node(task)
        new_node.next = self.head
        self.head = new_node

    def remove_task(self):
        if self.head is None:
            print("No tasks to remove.")
            return
        if self.head.next is None:
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    def display_tasks(self):
        if self.head is None:
            print("No tasks available.")
            return
        temp = self.head
        print("\n--- Task List ---")
        while temp:
            print(temp.data)
            temp = temp.next
        print("-----------------")

task_manager = TaskManager()
task_manager.add_task("Task 1")
task_manager.add_task("Task 2")
task_manager.add_task("Task 3")
task_manager.display_tasks()
task_manager.remove_task()
task_manager.display_tasks()
