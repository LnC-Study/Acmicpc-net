def data_in():
    global n, r, board, laser, direction
    n, r = list(map(int, input().split()))
    board = list(list(0 for i in range(n + 2)) for i in range(n + 2))
    for i in range(r):
        a, b = list(map(int, input().split()))
        board[a][b] = 1  # 1 means mirror
    laser = list(map(int, input().split()))
    direction = {1: 'U', 2: 'R', 3: 'D', 4: 'L'}


def moveUp(x, y):
    offset = 1
    while x > 0:
        x = x - 1
        if board[x][y] == 1:
            offset = (offset % 4) + 1
            break
    return direction[offset], x, y


def moveDown(x, y):
    offset = 3
    while x < n+1:
        x = x + 1
        if board[x][y] == 1:
            offset = (offset % 4) + 1
            break
    return direction[offset], x, y


def moveLeft(x, y):
    offset = 4
    while y > 0:
        y = y - 1
        if board[x][y] == 1:
            offset = (offset % 4) + 1
            break
    return direction[offset], x, y


def moveRight(x, y):
    offset = 2
    while y < n+1:
        y = y + 1
        if board[x][y] == 1:
            offset = (offset % 4) + 1
            break
    return direction[offset], x, y


def solution():
    if laser[0] == 0:  # moveDown
        dirIndex = direction[3]
    elif laser[0] == n + 1:  # moveUp
        dirIndex = direction[1]
    elif laser[1] == 0:  # moveRight
        dirIndex = direction[2]
    else:  # moveLeft
        dirIndex = direction[4]

    curX, curY = laser[0], laser[1]
    while True:
        if dirIndex == 'U':
            dirIndex, curX, curY = moveUp(curX, curY)
        elif dirIndex == 'R':
            dirIndex, curX, curY = moveRight(curX, curY)
        elif dirIndex == 'D':
            dirIndex, curX, curY = moveDown(curX, curY)
        else:  # dirIndex == 'L'
            dirIndex, curX, curY = moveLeft(curX, curY)

        if curX == 0 or curY == 0:
            return curX, curY


if __name__ == '__main__':
    cnt = int(input())
    for i in range(cnt):
        data_in()
        x, y = solution()
        print(x, y)
