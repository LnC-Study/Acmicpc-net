class Node:
    def __init__(self, _pos, _level):
        self.pos = _pos
        self.level = _level


def data_in():
    global N, space
    N = int(input())
    space = list(list(map(int, input().split())) for _ in range(N))


def bfs_improved(rootNode, cur_size):
    direction = {"U": (-1, 0), "L": (0, -1), "D": (1, 0), "R": (0, 1)}
    dist_records = dict()
    queue = [rootNode.pos]
    dist_records[rootNode.pos] = rootNode.level
    visited = list()
    candidate = list()

    flag_pos = None

    while queue:
        cur_pos = queue.pop(0)
        visited.append(cur_pos)
        if queue:
            flag_pos = queue[0]
        # 4방위 검사
        for offset in direction:
            next_pos = (cur_pos[0] + direction[offset][0], cur_pos[1] + direction[offset][1])
            if -1 < next_pos[0] < N and -1 < next_pos[1] < N:
                next_dist = dist_records[cur_pos] + 1
                if not (next_pos in visited) and not (next_pos in queue):
                    if not(space[next_pos[0]][next_pos[1]] > cur_size):
                        queue.append(next_pos)
                        dist_records[next_pos] = next_dist
                    if 0 < space[next_pos[0]][next_pos[1]] < cur_size:
                        candidate.append(next_pos)
                        dist_records[next_pos] = next_dist
        if flag_pos:
            if abs(dist_records[flag_pos] - dist_records[cur_pos]) == 1 and len(candidate) > 0:
                break

    # 후보군 검사
    if len(candidate) > 0:
        result = candidate[0]
        for i in range(1, len(candidate)):
            if (candidate[i][0] < result[0]) or (candidate[i][0] == result[0] and candidate[i][1] < result[1]):
                if dist_records[candidate[i]] <= dist_records[result]:
                    result = candidate[i]
        return result, dist_records[result]
    return None, None


def bfs_deprecated(rootNode, cur_size):
    direction = {"U": (-1, 0), "L": (0, -1), "D": (1, 0), "R": (0, 1)}
    queue = [rootNode]
    visited = list()
    candidate = list()
    flagNode = None

    while queue:
        curNode = queue.pop(0)
        visited.append(curNode.pos)
        if queue:
            flagNode = queue[0]
        # 4방위 검사
        for offset in direction:
            next_pos = (curNode.pos[0] + direction[offset][0], curNode.pos[1] + direction[offset][1])
            if -1 < next_pos[0] < N and -1 < next_pos[1] < N:
                nextNode = Node(next_pos, curNode.level + 1)
                if not (next_pos in visited) and not (nextNode in queue):
                    if not(space[next_pos[0]][next_pos[1]] > cur_size):
                        queue.append(nextNode)
                    if 0 < space[next_pos[0]][next_pos[1]] < cur_size:
                        candidate.append(nextNode)
        if flagNode:
            if abs(flagNode.level - curNode.level) == 1 and len(candidate) > 0:
                break

    # 후보군 검사
    if len(candidate) > 0:
        result = candidate[0]
        for i in range(1, len(candidate)):
            if (candidate[i].pos[0] < result.pos[0]) or (candidate[i].pos[0] == result.pos[0] and candidate[i].pos[1] < result.pos[1]):
                if candidate[i].level <= result.level:
                    result = candidate[i]
        return result.pos, result.level
    return None, None


def bfs(rootNode, cur_size):
    direction = {"U": (-1, 0), "L": (0, -1), "D": (1, 0), "R": (0, 1)}
    queue = [rootNode.pos]
    initial_flag = True
    visited = []
    result = None
    result_dist = None

    dist_records = dict()
    dist_records[rootNode.pos] = 0

    while queue:
        way_point = queue.pop(0)
        dist = dist_records[way_point]
        visited.append(way_point)

        # 결과 판단
        if 0 < space[way_point[0]][way_point[1]] < cur_size:
            if initial_flag:
                result = way_point
                result_dist = dist
                initial_flag = False
            else:
                if dist > result_dist: # 더이상 최단 거리가 아니라면
                    return result, result_dist

                if (result[0] > way_point[0]) or (result[0] == way_point[0] and result[1] > way_point[0]):
                    result = way_point
                    result_dist = dist

        # 4방위 조사
        for offset in direction:
            temp_x = way_point[0] + direction[offset][0]
            temp_y = way_point[1] + direction[offset][1]
            if -1 < temp_x < N and -1 < temp_y < N:
                if (not ((temp_x, temp_y) in visited)) and (not ((temp_x, temp_y) in queue)):
                    if (0 <= space[temp_x][temp_y] <= cur_size):
                        queue.append((temp_x, temp_y))
                        dist_records[(temp_x, temp_y)] = dist + 1
    return result, result_dist


def solution():
    total_time = 0
    feed_cnt = 0
    shark_pos = (-1, -1)
    shark_size = 2

    # 상어 초기 위치 파악
    for x in range(N):
        for y in range(N):
            if space[x][y] == 9:
                shark_pos = (x, y)
                break
        if shark_pos[0] != -1:
            space[shark_pos[0]][shark_pos[1]] = 0
            break

    while True:
        root = Node((shark_pos[0], shark_pos[1]), 0)
        #pos, level = bfs(root, shark_size)
        #pos, level = bfs_deprecated(root, shark_size)
        pos, level = bfs_improved(root, shark_size)
        if pos is None:
            break

        shark_pos = pos
        total_time = total_time + level
        space[pos[0]][pos[1]] = 0
        feed_cnt = feed_cnt + 1
        if feed_cnt == shark_size:
            feed_cnt = 0
            shark_size = shark_size + 1
        #print(shark_pos, total_time, shark_size)

    return total_time


if __name__ == "__main__":
    data_in()
    answer = solution()
    print(answer)
