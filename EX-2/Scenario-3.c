class InfixToPostfix:
    def __init__(self):
        self.stack = []
        self.output = []
        self.precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}

    def is_operand(self, char):
        return char.isalnum()

    def precedence_of(self, operator):
        return self.precedence.get(operator, 0)

    def push(self, char):
        self.stack.append(char)

    def pop(self):
        return self.stack.pop() if self.stack else None

    def convert(self, infix):
        for char in infix:
            if self.is_operand(char):
                self.output.append(char)
            elif char == '(':
                self.push(char)
            elif char == ')':
                while self.stack and self.stack[-1] != '(':
                    self.output.append(self.pop())
                self.pop()  # Pop the '('
            else:  # Operator
                while (self.stack and self.precedence_of(self.stack[-1]) >= self.precedence_of(char)):
                    self.output.append(self.pop())
                self.push(char)

        while self.stack:
            self.output.append(self.pop())

        return ''.join(self.output)
infix_expr = "A+B*(C^D-E)"
calculator = InfixToPostfix()
postfix_expr = calculator.convert(infix_expr)
print(f"Infix: {infix_expr}")
print(f"Postfix: {postfix_expr}")
