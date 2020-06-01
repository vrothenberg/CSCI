def calc(expression):

    def operate():
        operator = opStack.pop()
        operand2 = valStack.pop()
        operand1 = valStack.pop()

        if operator == '+':
            valStack.append(operand1 + operand2)
        elif operator == '-':
            valStack.append(operand1 - operand2)
        elif operator == '*':
            valStack.append(operand1 * operand2)
        elif operator == '/':
            valStack.append(operand1 / operand2)
        return


    precedence = {
        '+': 1, 
        '-': 1,
        '*': 2,
        '/': 2,
        '(': 3,
        ')': 3} 

    operators = '+-*/'       
        
    valStack = []
    opStack = []

    i = 0
    while i < len(expression):
        if expression[i].isnumeric():
            print(i, 'numeric')
            num = expression[i]
            i += 1
            while i < len(expression) and expression[i].isnumeric():
                num += expression[i]
                i += 1 
            valStack.append(int(num))
            print(i, "valStack:",  valStack)
        else:
            if expression[i] == '(':
                opStack.append(expression[i])
            elif expression[i] == ')':
                while opStack[-1] != '(':
                    operate()
                opStack.pop()
            elif expression[i] in operators:
                print(i, 'in operators', valStack, opStack)
                while opStack and precedence[opStack[-1]] >= precedence[expression[i]]:
                    operate()
                opStack.append(expression[i])
            i += 1

        print('end', i, valStack, opStack)

    #while opStack:
        #operate()

    return valStack[0]







tests = [
    ["1 + 1", 2],
    ["8/16", 0.5],
    ["3 -(-1)", 4],
    ["2 + -2", 0],
    ["10- 2- -5", 13],
    ["(((10)))", 10],
    ["3 * 5", 15],
    ["-7 * -(6 / 3)", 14]
]
for test in tests:
    print("calc(test[0]):", calc(test[0]), test[1])