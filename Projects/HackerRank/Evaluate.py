def calc(expression):
    precedence = {
        '+': 1, 
        '-': 1,
        '*': 2,
        '/': 2,
        '(': 3,
        ')': 3}        
        
    stack = []
    output = []
    operators = '+-*/'
    i = 0
    while i < len(expression):
        if expression[i].isnumeric():
            num = expression[i]
            i+= 1
            while i < len(expression) and expression[i].isnumeric():
                num += expression[i]
                i +=1 
            output.append(num)
        else:
            if expression[i] in operators:
                while stack and precedence[stack[-1]] >= precedence[expression[i]] and stack[-1] != '(':
                    output.append(stack.pop())
                stack.append(expression[i])
            elif expression[i] == '(':
                stack.append('(')
            elif expression[i] == ')':
                while stack[-1] != '(':
                    output.append(stack.pop())
                if stack[-1] == '(':
                    stack.pop()
            i += 1

    while stack:
        output.append(stack.pop())
            
    print("Output:",  output)
    result = []
    for i,o in enumerate(output):
        print("i:", i, "result", o)
        if o.isnumeric():
            result.append(int(o))
        elif o in operators:
            op2 = result.pop()
            op1 = result.pop()
            if o == '+':
                result.append(op1 + op2)
            elif o == '-':
                if i+1 < len(output) and output[i+1] == '-':
                    op2 = -op2
                    result.append(op1)
                    result.append(op2)
                else:
                    result.append(op1 - op2) 
            elif o == '*':
                result.append(op1 * op2)
            elif o == '/':
                result.append(op1 / op2)
            print(result)
    print(result)


    return result[0]

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
test = tests[3]
print("calc(test[0]):", calc(test[0]), test[1])