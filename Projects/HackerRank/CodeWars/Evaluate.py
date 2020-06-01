def calc(expression):
    precedence = {
        '+': 1, 
        '-': 1,
        '*': 2,
        '/': 2,
        '(': 3,
        ')': 3}        
        
    opstack = []
    output = []
    operators = '+-*/'
    i = 0
    while i < len(expression):
        if expression[i].isnumeric():
            #print(i, 'numeric:', expression[i])
            num = expression[i]
            i += 1
            while i < len(expression) and expression[i].isnumeric():
                num += expression[i]
                i += 1 
            output.append(num)
            #print(i, "Output:",  output)
        else:
            #print('else')
            if expression[i] in operators:
                while opstack and precedence[opstack[-1]] >= precedence[expression[i]] and opstack[-1] != '(':
                    output.append(opstack.pop())
                    #print(i, "Output:",  output)
                opstack.append(expression[i])
                #print(i, "opstack:",  opstack)
            elif expression[i] == '(':
                opstack.append('(')
            elif expression[i] == ')':
                while opstack[-1] != '(':
                    output.append(opstack.pop())
                if opstack[-1] == '(':
                    opstack.pop()
            i += 1
        #print('End', i, 'Output:', output, 'Opstack:', opstack)

    while opstack:
        output.append(opstack.pop())
            
    #print("Output:",  output)
    result = []
    for i,o in enumerate(output):
        #print("i:", i, "result:", result, "o:", o)
        if o.isnumeric():
            result.append(int(o))
        elif o in operators:
            op2 = result.pop()
            op1 = 0
            if result:
                op1 = result.pop()
            if o == '+':
                result.append(op1 + op2)
            elif o == '-':
                if i+1 < len(output) and output[i+1] == '-':
                    #print('Subtraction if')
                    op2 = -op2
                    result.append(op1)
                    result.append(op2)
                else:
                    #print('op1 - op2')

                    result.append(op1 - op2) 
            elif o == '*':
                result.append(op1 * op2)
            elif o == '/':
                result.append(op1 / op2)
            #print(result)
    #print(result)


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
for test in tests:
    print("calc(test[0]):", calc(test[0]), test[1])