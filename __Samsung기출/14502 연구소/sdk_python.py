from itertools import combinations

def data_in():
    height, width = map( int, input().split())
    return height, width, [ list( map( int, input().split())) for _ in range( height)]

def get_blanks_N_viruses():
    blanks, viruses = [], []
    for row in range( height):
        for col in range( width):
            if board[row][col] == 0: blanks.append( (row, col))
            elif board[row][col] == 2: viruses.append( (row, col))

    return blanks, viruses

def is_able_to_go( pos):
    return 0 <= pos[0] < height and 0 <= pos[1] < width and \
           not visited[ pos[0]][ pos[1]] and board[ pos[0]][pos[1]] == 0

DIRS = [ (-1,0), (0,1), (1,0), (0,-1)]
def get_safe_area( wall_combination, area):
    global board, visited

    visited = [[False for col in range( width)] for row in range( height)]
    for wall in wall_combination: board[ wall[0]][ wall[1]] = 1

    for virus_pos in viruses:
        queue = [virus_pos]
        visited[ virus_pos[0]][ virus_pos[1]] = True
        while len( queue) > 0:
            current_pos = queue[0]; queue.pop(0)
            for dir in DIRS:
                next_pos = (current_pos[0] + dir[0], current_pos[1] + dir[1])
                if is_able_to_go( next_pos):
                    visited[ next_pos[0]][ next_pos[1]] = True
                    area -= 1
                    queue.append( next_pos)

    for wall in wall_combination: board[ wall[0]][ wall[1]] = 0

    return area - 3

def solution():
    global viruses

    blanks, viruses = get_blanks_N_viruses()
    wall_combinations = combinations( blanks, 3)

    ans = -1
    for wall_combination in wall_combinations:
        ans = max( ans, get_safe_area( wall_combination, len( blanks)))

    return ans

if __name__ == '__main__':
    global height, width, board
    height, width, board = data_in()
    ans = solution()
    print( ans)