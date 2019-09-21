# 16234 연구소 (정답율 35.165% / 2시간 소요 / 시간초과~)
import sys
sys.setrecursionlimit(100000)

def data_in():
    n, l, r = list(map(int, input().split()))
    nations = list(list(int(i) for i in input().split()) for _ in range(n))
    return n, l, r, nations


def immigrate(set, num):
    for nation in set:
        input_map[nation[0]][nation[1]] = num


def dfs(x, y):
    if (x, y) in nations_to_be_union or (x, y) in visited:
        return 0
    nations_to_be_union.append((x, y))
    population = input_map[x][y]

    for offset in direction:
        nextX, nextY = (x+direction[offset][0], y+direction[offset][1])
        # 국경선 제거 가능할 때만 이동

        if -1 < nextX < N and -1 < nextY < N:
            diff = abs(input_map[x][y] - input_map[nextX][nextY])
            if L <= diff <= R:
                population += dfs(nextX, nextY)
    return population


def solution():
    global nations_to_be_union, visited, direction
    direction = {"L": (0, -1), "U": (-1, 0), "R": (0, 1), "D": (1, 0)}
    day = 0

    while(True):
        flag = False
        visited = list()
        # 전체 map 탐색
        for x in range(N):
            for y in range(N):
                # 연합에 속하지 않은 칸에 대해서
                if not ((x, y) in visited):
                    # 자료구조 초기화
                    nations_to_be_union = list()

                    # map[x][y]를 루트로 탐색 시작.
                    population = int(dfs(x, y) / len(nations_to_be_union))

                    # 탐색 완료 국가 표시.
                    visited.extend(nations_to_be_union)

                    # 이동 필요 시
                    if len(nations_to_be_union) > 1:
                        immigrate(nations_to_be_union, population)
                        flag = True
        # 국경 이동 노 필요.
        if not flag:
            break
        day = day + 1
    # end-while
    return day

if __name__ == "__main__":
    global N, L, R, input_map
    N, L, R, input_map = data_in()
    result = solution()
    print(result)
