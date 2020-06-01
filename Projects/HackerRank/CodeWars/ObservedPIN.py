import itertools

def get_pins(observed):
    keypad = {
    '1' : ['1','2','4'],
    '2' : ['1','2','3','5'],
    '3' : ['2','3','6'],
    '4' : ['1','4','5','7'],
    '5' : ['2','4','5','6','8'],
    '6' : ['3','5','6','9'],
    '7' : ['4','7','8'],
    '8' : ['5','7','8','9','0'],
    '9' : ['6','8','9'],
    '0' : ['8','0']
    }
    
    sequence = []
    for key in observed:
        sequence.append(keypad[key])

    combinations = sequence[0]

    for i in range(1, len(observed)):
        combinations = [x+y for x in combinations for y in sequence[i]]

    #print(sequence)
    return combinations

print(get_pins('11'))
        