def spiralize(size):
    # Make a snake
    spiral = [ [0] * size for i in range(size) ] 
    spiral[0][0:size] = [1]*size
    nextTurn = ['d','l','u', 'r']
    y,x = 0,size-1
    length = size-1
    numTurns = 0
    while length > 0:
        move = nextTurn[numTurns % 4]
        if move == 'r':
            # Right 
            print('Right', length, (y,x))
            spiral[y][x+1:x+1+length] = [1]*length 
            for i in spiral:
                print(i)
            x += length
        elif move == 'd':
            # Down 
            print('Down', length, (y,x))
            for i in range(length):
                y += 1
                spiral[y][x] = 1
            for i in spiral:
                print(i)
        
        elif move == 'l':
            # Left 
            print('Left', length, (y,x))
            spiral[y][x-length:x] = [1]*length
            x -= length
            for i in spiral:
                print(i)
        
        elif move == 'u':
            # Up
            print('Up', length, (y,x))
            for i in range(length):
                y -= 1
                spiral[y][x] = 1
            for i in spiral:
                print(i)
                
        numTurns += 1
        if numTurns % 2 == 0:
            length -= 2
        elif length == 1:
            break
        
        
    print('Complete') 
    return spiral

spiral = spiralize(9)
for i in spiral:
    print(i)