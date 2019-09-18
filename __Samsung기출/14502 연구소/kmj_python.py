# 14502 연구소 (정답율 54.799%)
from itertools import combinations
from copy import deepcopy


def data_in():
    n, m = list(map(int, input().split()))
    input_map = list(list(int(i) for i in input().split()) for i in range(n))
    return n, m, input_map


def dfs(map, virus_pos):
    direction = {"L": (-1, 0), "U": (0, -1), "R": (1, 0), "D": (0, 1)}
    stack = list()
    visited = list()

    stack.extend(virus_pos)

    while(stack):
        cur_pos = stack.pop()

        # 4방위 탐색
        for offset in direction:
            temp_pos = (cur_pos[0] + direction[offset][0], cur_pos[1] + direction[offset][1])
            if -1 < temp_pos[0] < n and -1 < temp_pos[1] < m:
                if map[temp_pos[0]][temp_pos[1]] == 0:
                    map[temp_pos[0]][temp_pos[1]] = 2
                    stack.append(temp_pos)
    return map


def solution(n, m, input_map):
    # 1. 빈칸, 바이러스칸 위치 리스트 생성
    empty_rooms = list()
    rooms_with_virus = list()
    for row in range(n):
        for col in range(m):
            temp = (row, col)
            if input_map[row][col] == 0:
                empty_rooms.append(temp)
            elif input_map[row][col] == 2:
                rooms_with_virus.append(temp)

    # 2. 벽 조합 생성
    max = 0
    for walls in combinations(empty_rooms, 3):
        # 2-1. 벽 후보군 적용
        temp_map = deepcopy(input_map)
        for wall in walls:
            temp_map[wall[0]][wall[1]] = 1

        # 2-2. dfs로 바이러스(2)를 증식
        temp_processed_map = dfs(temp_map, rooms_with_virus)

        # 2-3. 0 개수 세기
        result = 0
        for row in temp_processed_map:
            for room in row:
                if room == 0:
                  result = result + 1

        # 2-4. 최대 안전영역 크기 찾기
        if max < result:
            max = result

    return max


if __name__ == "__main__":
    n, m, input_map = data_in()
    result = solution(n, m, input_map)
    print(result)

