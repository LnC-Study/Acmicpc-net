TestCase = int(input())
answer = []


def down(row, col):
    global answer
    for cell in range(row+1, size+2):
        if rooms[cell][col] == 1: # 밑으로 내려가다가 거울 만나면
            left(cell, col)
            break

        if cell == size+1:
            answer = [cell, col]


def up(row, col):
    global answer
    for cell in range(row-1, -1, -1):
        if rooms[cell][col] == 1: # 위로 올라가다가 거울 만나면
            right(cell, col)
            break

        if cell == 0:
            answer = [cell, col]


def right(row, col):
    global answer
    for cell in range(col+1, size+2):
        if rooms[row][cell] == 1: # 오른쪽으로 가다가 거울 만나면
            down(row, cell)
            break

        if cell == size+1:
            answer = [row, cell]


def left(row, col):
    global answer
    for cell in range(col-1, -1, -1):
        if rooms[row][cell] == 1: # 밑으로 내려가다가 거울 만나면
            up(row, cell)
            break

        if cell == 0:
            answer = [row, cell]


def go(row, col):
    if row == 0:
        down(row, col)

    elif row == size+1:
        up(row, col)

    elif col == 0:
        right(row, col)

    else:
        left(row, col)


for _ in range(TestCase):
    size, m = list(map(int, input().split(' ')))
    rooms = [[0 for _ in range(0, size+2)] for _ in range(0, size+2)]
    mirrors = []

    for _ in range(m):
        row, col = tuple(map(int, input().split(' ')))
        rooms[row][col] = 1
        mirrors.append((row, col))

    lazer = tuple(map(int, input().split(' ')))

    go(lazer[0], lazer[1])
    print(answer[0], answer[1])
