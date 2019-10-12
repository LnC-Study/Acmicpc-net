import math


def data_in():
    global R, C, T, cleaner
    R, C, T = list(map(int, input().split()))
    m = list(list(i for i in map(int, input().split())) for i in range(R))
    cleaner = list()
    for row in range(R):
        if m[row][0] == -1:
            cleaner.append(row)
    return m


def circulate(map, option):
    clock = [["R", "U", "L", "D"], ["R", "D", "L", "U"]]

    x = cleaner[option]
    y = 1
    value = 0
    dir = 0
    while True:
        temp = map[x][y]
        if temp == -1:
            break
        map[x][y] = value

        value = temp
        if not (-1 < x + direction[clock[option][dir]][0] < R and -1 < y + direction[clock[option][dir]][1] < C):
            dir = dir + 1
        x = x + direction[clock[option][dir]][0]
        y = y + direction[clock[option][dir]][1]

    return map


def operate(input_map):
    global direction
    direction = {"L": (0, -1), "R": (0, 1), "U": (-1, 0), "D": (1, 0)}
    dirty_map = list(list(0 for i in range(C)) for _ in range(R))
    dirty_map[cleaner[0]][0] = -1
    dirty_map[cleaner[1]][0] = -1

    # 먼지칸 파악
    for row in range(R):
        for col in range(C):
            if input_map[row][col] != 0 and input_map[row][col] != -1:
                 # 상하좌우 조사
                near_room = list()
                for offset in direction:
                    x = row + direction[offset][0]
                    y = col + direction[offset][1]
                    if  -1 < x < R and -1 < y < C:
                        if input_map[x][y] != -1:
                            near_room.append((x, y))
                # 미세먼지 계산
                amount = math.floor(input_map[row][col] / 5)
                dirty_map[row][col] = dirty_map[row][col] + (input_map[row][col] - amount * len(near_room))
                for room in near_room:
                    dirty_map[room[0]][room[1]] = dirty_map[room[0]][room[1]] + amount

    # 상단 공기청정기 작동
    dirty_map = circulate(dirty_map, 0)
    dirty_map = circulate(dirty_map, 1)

    return dirty_map


def calculate_total_dust(result_map):
    sum = 0
    for row in result_map:
        for room in row:
            if room != -1 and room != 0:
                sum = sum + room
    return sum


def solution(before):
    result = before
    for _ in range(T):
        result = operate(result)
    return calculate_total_dust(result)


if __name__ == "__main__":
    initial_map = data_in()
    result = solution(initial_map)
    print(result)

