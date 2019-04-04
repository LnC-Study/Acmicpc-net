import collections

N, M = list(map(int, input().split(' ')))
rPos, cPos, initDir = list(map(int, input().split(' ')))
rooms = [list(map(int, input().split(' '))) for _ in range(N)]
direction = [(0, -1), (1, 0), (0, 1), (-1, 0)] # 차례대로 북,서,남,동 --> 0, 1, 2, 3 쪽에서의 왼쪽
di = {0: 0, 1: 3, 2: 2, 3: 1} # 차례대로 북,동,남,서 --> 0, 1, 2, 3 쪽에서의 왼쪽


class cleaner:
    def __init__(self, row, col, dir, N, M):
        self.row = row
        self.col = col
        self.dir = dir
        self.visited = rooms
        self.done = 0
        self.queue = collections.deque([])
        self.back = 1

    def is_in(self, row, col):
        if (0 <= row < M) and (0 <= col < N):
            return True

        return False

    def go(self):
        self.visited[self.row][self.col] = 1
        self.queue.append((self.row, self.col))
        self.done += 1

        while len(self.queue) > 0:
            cur = self.queue.popleft()

            self.back = True
            for next in range(4):
                if self.dir >= 4:
                    self.dir = 0

                curDir = direction[self.dir] # 현재 방향에서 왼쪽이 curDir
                nextRow, nextCol = cur[0] + curDir[0], cur[1] + curDir[1] # 현위치에서 바라보는 방향으로 왼쪽칸
                self.dir += 1
                if self.is_in(nextRow, nextCol) is True:
                    if self.visited[nextRow][nextCol] == 0: # 이게 격자 안에 있고, 방문하지 않은거
                        self.visited[nextRow][nextCol] = 1
                        self.queue.append((nextRow, nextCol))
                        self.done += 1
                        self.back = False
                        break

            if self.back is True:
                if self.dir == 0:
                    back = (cur[0]+1, cur[1])
                elif self.dir == 1:
                    back = (cur[0], cur[1]+1)
                elif self.dir == 2:
                    back = (cur[0]-1, cur[1])
                else:
                    back = (cur[0], cur[1]-1)

                if self.is_in(back[0], back[1]):
                    self.queue.appendleft(back)

        return self.done


robot = cleaner(rPos, cPos, di[initDir], N, M)
print(robot.go())

