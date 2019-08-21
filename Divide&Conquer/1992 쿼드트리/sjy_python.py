length = int(input())

square = []

for cnt in range(length):
    square.append(list(input()))


def compress(x, y, len): # 0,0,8
    for yCur in range(y, y+len):
        if square[yCur][x:x+len].count(square[yCur][x]) is not len: # 현재 가로줄에서 처음꺼랑 같은게 끝까지 나오지 않는다면 --> 분할
            print('(', end='')
            compress(x, y, len // 2) # 1분면
            compress(x+(len//2), y, len // 2) # 2분면
            compress(x, y+(len//2), len // 2) # 3분면
            compress(x+(len//2), y+(len//2), len // 2) # 4분면
            print(')', end='') # 어차피 처음에꺼는 무조건 print 함
            return

    print(str(square[y][x]), end='')


compress(0, 0, length)
