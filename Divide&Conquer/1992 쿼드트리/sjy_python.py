length = int(input())

square = []

for cnt in range(length):
    square.append(list(input()))


def compress(x, y, len): # 0,0,8
    print('('+square[y][x], end='') # 어차피 처음에꺼는 무조건 print 함

    for yCur in range(y, len):
        if square[yCur][x:x+len].count(square[yCur][x]) is not len: # 처음꺼랑 같은게 끝까지 나오지 않는다면
            compress(x, yCur, len // 2) # 1분면
            compress(x+(len//2), yCur, len // 2) # 2분면
            compress(x, yCur+(len//2), len // 2) # 3분면
            compress(x+(len//2), yCur+(len//2), len // 2) # 4분면




compress(0, 0, length)


# 8
# 11110000
# 11110000
# 00011100
# 00011100
# 11110000
# 11110000
# 11110011
# 11110011
