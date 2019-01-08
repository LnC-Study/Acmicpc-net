def get_decreasing_number(_N):
    MAX_NUMBER = 1023
    if _N >= MAX_NUMBER : return -1

    numbers = []
    for idx in range(1, MAX_NUMBER+1):
        binaryNumbers = str( bin(idx + 1024)[3:])
        currentNumber = "".join([str(digit) for digit in range(9, -1, -1) \
                                 if binaryNumbers[digit] == '1'])
        numbers.append( int( currentNumber))

    numbers = sorted( numbers)
    return numbers[_N]

if __name__ == '__main__':
    N = int(input())
    ans = get_decreasing_number( N)
    print( ans)