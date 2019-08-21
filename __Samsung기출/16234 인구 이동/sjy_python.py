N, L, R = list(map(int, input().split(' ')))

map = [list(map(int, input().split(' '))) for _ in range(N)]
visited = []
stack = []
total = 0

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def union(row, col):
    global total
    isPossible = False
    visited[row][col] = True
    stack.append((row, col))
    total += map[row][col]

    for next in range(4):
        nextX, nextY = col + dx[next], row + dy[next]
        if (0 <= nextX < N) and (0 <= nextY < N) and (L <= abs(map[nextY][nextX] - map[row][col]) <= R) and visited[nextY][nextX] is False:
            union(nextY, nextX)
            isPossible = True

    return isPossible


def calc():
    change = total // len(stack)
    for nation in stack:
        map[nation[0]][nation[1]] = change


def shift():
    global visited, total, stack
    ret = 0

    for _ in range(2000):
        visited = [[False for _ in range(N)] for _ in range(N)]
        finished = True
        for row in range(N):
            for col in range(N):
                total = 0
                stack = []
                if union(row, col) is True:
                    finished = False
                    calc()

        if finished is True:
            return ret
        ret += 1


print(shift())
