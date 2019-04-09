N, M = list(map(int, input().split(' ')))
rPos, cPos, initDir = list(map(int, input().split(' ')))
rooms = [list(map(int, input().split(' '))) for _ in range(N)]
direction = [(0, -1), (1, 0), (0, 1), (-1, 0)] # 차례대로 북,서,남,동 --> 0, 1, 2, 3 쪽에서의 왼쪽
di = {0: 0, 1: 3, 2: 2, 3: 1} # 차례대로 북,동,남,서 --> 0, 1, 2, 3 쪽에서의 왼쪽


class cleaner:
    def __init__(self, row, col, dir):
        self.row = row
        self.col = col
        self.dir = dir
        self.visited = rooms
        self.done = 0
        self.queue = []
        self.flag = True

    def is_in(self, row, col):
        if (0 <= col < M) and (0 <= row < N):
            return True

        return False

    def go(self):
        self.visited[self.row][self.col] = 2
        self.queue.append((self.row, self.col))
        self.done += 1

        while len(self.queue) > 0:
            curPos = self.queue.pop()

            self.flag = True
            for next in range(4):
                left = direction[self.dir] # 현재 방향에서 왼쪽이 curDir

                self.dir += 1
                if self.dir >= 4:
                    self.dir = 0

                nextRow, nextCol = curPos[0] + left[0], curPos[1] + left[1] # 현위치에서 바라보는 방향으로 왼쪽칸
                if self.is_in(nextRow, nextCol) is True:
                    if self.visited[nextRow][nextCol] == 0: # 이게 격자 안에 있고, 방문하지 않은거
                        self.visited[nextRow][nextCol] = 2
                        self.queue.append((nextRow, nextCol))
                        self.done += 1
                        self.flag = False
                        break

            if self.flag is True:
                if self.dir == 0:
                    back = (curPos[0] + 1, curPos[1])

                elif self.dir == 1:
                    back = (curPos[0], curPos[1] + 1)

                elif self.dir == 2:
                    back = (curPos[0] - 1, curPos[1])

                else:
                    back = (curPos[0], curPos[1] - 1)

                if self.is_in(back[0], back[1]) and self.visited[back[0]][back[1]] != 1:
                    self.queue.append(back)

                else:
                    return self.done


robot = cleaner(rPos, cPos, di[initDir])
print(robot.go())

