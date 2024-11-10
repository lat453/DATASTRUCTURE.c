class Node:
    def __init__(self, move):
        self.move = move
        self.next = None

class MoveStack:
    def __init__(self):
        self.top = None

    def push(self, move):
        new_node = Node(move)
        new_node.next = self.top
        self.top = new_node
        print(f"Move pushed: {move}")

    def pop(self):
        if not self.top:
            print("No moves to pop.")
            return None
        move = self.top.move
        self.top = self.top.next
        print(f"Move popped: {move}")
        return move

    def display_moves(self):
        if not self.top:
            print("No moves in the stack.")
            return
        print("\n--- Current Moves Stack ---")
        temp = self.top
        while temp:
            print(temp.move)
            temp = temp.next
        print("---------------------------")
move_stack = MoveStack()
move_stack.push("Move 1")
move_stack.push("Move 2")
move_stack.push("Move 3")
move_stack.display_moves()
move_stack.pop()
move_stack.display_moves()
move_stack.pop()
move_stack.display_moves()
