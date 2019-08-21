import collections

COL, ROW = list(map(int, input().split(' ')))
map = [list(map(int, input().split(' '))) for _ in range(ROW)]
visited = [[False for _ in range(COL)] for _ in range(ROW)]

direction = [(0, -1), (-1, 0), (0, 1), (1, 0)] # 서북동남
section = 0
area = []
queue = collections.deque([])
roomNum = [[0 for _ in range(COL)] for _ in range(ROW)]


def path_find(cell):
    available = []

    if cell & 1 == 0:
        available.append(0)
    if cell & 2 == 0:
        available.append(1)
    if cell & 4 == 0:
        available.append(2)
    if cell & 8 == 0:
        available.append(3)

    return available


def is_in(row, col):
    return 0 <= row < ROW and 0 <= col < COL


def bfs(row, col):
    visited[row][col] = True
    queue.append((row, col))
    roomNum[row][col] = section
    cnt = 1

    while len(queue) > 0:
        cur = queue.popleft()

        for next in path_find(map[cur[0]][cur[1]]):
            nextRow, nextCol = direction[next][0] + cur[0], direction[next][1] + cur[1]
            if is_in(nextRow, nextCol):
                if visited[nextRow][nextCol] is False:
                    visited[nextRow][nextCol] = True
                    roomNum[nextRow][nextCol] = section
                    cnt += 1
                    queue.append((nextRow, nextCol))

    area.append(cnt)


def collapsing():
    tmp = []

    for row in range(ROW):
        for col in range(COL):
            for next in range(4):
                nextRow, nextCol = row + direction[next][0], col + direction[next][1]
                if is_in(nextRow, nextCol):
                    if roomNum[row][col] != roomNum[nextRow][nextCol]:
                        tmp.append(area[roomNum[row][col]] + area[roomNum[nextRow][nextCol]])

    return max(tmp)


for row in range(ROW):
    for col in range(COL):
        if visited[row][col] is False:
            bfs(row, col)
            section += 1


print(section)
print(max(area))
print(collapsing())
