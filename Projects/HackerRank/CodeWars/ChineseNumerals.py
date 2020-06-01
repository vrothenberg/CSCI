
'''
def to_chinese_numeral(n):
    numerals = {
        "-":"负",
        ".":"点",
        0:"零",
        1:"一",
        2:"二",
        3:"三",
        4:"四",
        5:"五",
        6:"六",
        7:"七",
        8:"八",
        9:"九",
        10:"十",
        100:"百",
        1000:"千",
        10000:"万"
    }
    chinese = ''
    ns = str(n).split('.')
    whole = ns[0]
    if whole[0] == '-':
        chinese += numerals['-']
        whole = whole[1:]
    places = len(whole)
    for i in range(places):
        num = int(whole[i])
        mag = 10 ** (places - i - 1)
        rem = num % mag  
        div = num // mag
        print(num, mag, rem, div)
        if div or places == 1:
            chinese += numerals[div]
            if mag > 1:
                chinese += numerals[mag]

    if len(ns)>1:
        fraction = ns[1]
        chinese += numerals['.']
        places = len(fraction)
        for i in range(places):
            chinese += numerals[int(fraction[i])]


    return chinese

'''


def to_chinese_numeral(n):

    def sub19(numStr):
        numInt = int(numStr)
        chinese = ''

        if numInt <= 10:
            chinese += numerals[numInt]
        elif numInt <= 19:
            chinese += numerals[10] + numerals[int(numStr[1])]
        return chinese

    numerals = {
        "-":"负",
        ".":"点",
        0:"零",
        1:"一",
        2:"二",
        3:"三",
        4:"四",
        5:"五",
        6:"六",
        7:"七",
        8:"八",
        9:"九",
        10:"十",
        100:"百",
        1000:"千",
        10000:"万"
    }

    chinese = ''
    ns = str(n).split('.')
    whole = ns[0]

    if whole[0] == '-':
        chinese += numerals['-']
        whole = whole[1:]

    places = len(whole)
    wholeInt = int(whole)
    if sub19(whole):
        chinese += sub19(whole)
    else:
        zeroFlag = False
        for i in range(places):
            digit = int(whole[i])
            exp = places - i - 1
            mag = 10 ** exp
            #print(digit, mag, exp)
            if digit:
                if zeroFlag:
                    chinese += numerals[0]
                    zeroFlag = False 
                chinese += numerals[digit]
                if exp:
                    chinese += numerals[mag]
            else:
                zeroFlag = True

    if len(ns) > 1:
        fraction = ns[1]
        chinese += numerals['.']
        places = len(fraction)
        for i in range(places):
            chinese += numerals[int(fraction[i])]

    return chinese





print(to_chinese_numeral(9) == '九')
print(to_chinese_numeral(-5) == '负五')
print(to_chinese_numeral(0.5) == '零点五')
print(to_chinese_numeral(10) == '十')
print(to_chinese_numeral(110) == '一百一十')
print(to_chinese_numeral(111) == '一百一十一')
print(to_chinese_numeral(1000) == '一千')
print(to_chinese_numeral(10000) == '一万')
print(to_chinese_numeral(10006) == '一万零六')
print(to_chinese_numeral(10306.005) == '一万零三百零六点零零五')
