def data_in():
    size = int( input())
    return size, [ list( map( int, input().split())) for _ in range( size)]

def get_shark_pos():
    for row in range( size):
        for col in range( size):
            if board[row][col] == 9 : return ( row, col)

def is_in( pos):
    return 0 <= pos[0] < size and 0 <= pos[1] < size

DIRS = [(-1,0), (1,0), (0,-1), (0,1)]
def get_nearest_fish( shark, level):
    current_dist, fish = [ shark], []
    distance, visited[ shark[0]][ shark[1]] = 0, True

    while len( current_dist) > 0:
        next_dist, flag = [], False
        distance += 1
        for current_pos in current_dist:
            for dir in DIRS:
                next_pos = ( current_pos[0] + dir[0], current_pos[1] + dir[1])

                if not is_in( next_pos) or visited[ next_pos[0]][ next_pos[1]]: continue
                if board[ next_pos[0]][ next_pos[1]] <= level:
                    next_dist.append( next_pos)
                    visited[ next_pos[0]][ next_pos[1]] = True
                    if 0 < board[ next_pos[0]][ next_pos[1]] < level:
                        fish.append( next_pos)
                        flag = True

        if not flag:
            current_dist = next_dist
            continue

        fish = sorted( fish)
        board[ fish[0][0]][ fish[0][1]] = 0
        return fish[0], distance

    return 0, 0

def initialize_visited():
    return [[False for _ in range( size)] for __ in range( size)]

def solution( shark, level, count):
    global visited
    total_time = 0
    while True:
        visited = initialize_visited()
        next, time = get_nearest_fish( shark, level)

        if time == 0: break
        shark = next
        count += 1
        total_time += time
        if count == level: level += 1; count = 0

    return total_time

if __name__ == '__main__':
    global size, board

    size, board = data_in()
    shark = get_shark_pos()
    board[ shark[0]][ shark[1]] = 0
    answer = solution( shark, 2, 0)

    print( answer)