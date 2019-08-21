DIRECTIONS = {'L': 1, 'U': 2, 'R': 4, 'D': 8}
STEPS = {'L': (0, -1), 'U': (-1,0), 'R': (0,1), 'D': (1,0)}

def data_in():
    N, M = map(int, input().split())
    castle = [list(map(int, input().split())) for _ in range(M)]
    return N, M, castle

def is_in(pos):
    return 0 <= pos[0] < height and 0 <= pos[1] < width

def is_able_to_go(current, direction):
    return not (castle[current[0]][current[1]] & DIRECTIONS[direction])

def get_next_pos(current, direction):
    step = STEPS[direction]
    return (current[0] + step[0], current[1] + step[1])

def classify():
    room_tag, rooms = 1, {}
    classified = [[0 for col in range(width)] for row in range(height)]
    visited = [[False for col in range(width)] for row in range(height)]

    def spread(row, col, tag):
        pos_queue, area = [(row, col)], 0
        visited[row][col] = True

        while len(pos_queue) > 0:
            current = pos_queue[0]; del pos_queue[0]
            classified[current[0]][current[1]] = tag
            area += 1

            for direction in DIRECTIONS:
                next_pos = get_next_pos(current, direction)
                if not is_able_to_go(current, direction) and is_in(next_pos):
                    rooms[tag]['connected'].add(classified[next_pos[0]][next_pos[1]])
                elif is_in(next_pos) and not visited[next_pos[0]][next_pos[1]]:
                    visited[next_pos[0]][next_pos[1]] = True
                    pos_queue.append(next_pos)

        return area

    for row in range(height):
        for col in range(width):
            if classified[row][col] == 0:
                rooms[room_tag] = {
                    'start': (row, col),
                    'connected': set()
                }
                rooms[room_tag]['area'] = spread(row, col, room_tag)
                room_tag += 1

    return classified, rooms

def get_result(rooms):
    count, max_area = len(rooms), max(map(lambda x: rooms[x]['area'], rooms))

    max_union_area = -1
    for tag in rooms:
        for connected_room_tag in rooms[tag]['connected']:
            if connected_room_tag in (0, tag): continue

            union_area = rooms[tag]['area'] + rooms[connected_room_tag]['area']
            max_union_area = max(max_union_area, union_area)

    return count, max_area, max_union_area

def solution():
    classified, rooms = classify()
    return get_result(rooms)

if __name__ == '__main__':
    global width, height, castle

    width, height, castle = data_in()
    ans = solution()

    print(f'{ans[0]}\n{ans[1]}\n{ans[2]}')