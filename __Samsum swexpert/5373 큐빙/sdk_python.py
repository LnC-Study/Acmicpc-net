from operator import sub, add

U, D, L, R, B, F = (0,0,-1), (0,0,1), (-1,0,0), (1,0,0), (0,-1,0), (0,1,0)
WHITE, YELLOW, RED, ORANGE, GREEN, BLUE = 'w','y','r','o','g','b'
CENTERS = {'U': (1,1,0), 'D': (1,1,2), 'F': (1,2,1), 'B': (1,0,1), 'L': (0,1,1), 'R':(2,1,1)}
DIRECTIONS = {'U': (0,0,-1), 'D': (0,0,1), 'F': (0,1,0), 'B': (0,-1,0), 'L': (-1,0,0), 'R': (1,0,0)}

class Cell:
    def __init__(self): self.state = {}

def data_in():
    return int(input()), input().split()

def initialize_cube():
    cube = [[ [ Cell() for _ in range( 3)] for __ in range(3)] for ___ in range(3)]
    # fill upper
    for x in range(3):
        for y in range(3):
            for z in range(3):
                if z == 0: cube[x][y][z].state[U] = WHITE
                if z == 2: cube[x][y][z].state[D] = YELLOW
                if x == 0: cube[x][y][z].state[L] = GREEN
                if x == 2: cube[x][y][z].state[R] = BLUE
                if y == 0: cube[x][y][z].state[B] = ORANGE
                if y == 2: cube[x][y][z].state[F] = RED

    return cube

def get_other_two_axes( direction):
    # return two tuples
    result, default = [], [0,0,0]
    for idx, dir in enumerate( direction):
        if dir == 0:
            default[idx] = 1
            result.append( tuple( default))
            default[idx] = 0

    return result

def get_inversed_axis( direction):
    return tuple( map( lambda x: -x, direction))

def minus_tuples( tuple1, tuple2): return tuple( map( sub, tuple1, tuple2))
def plus_tuples( tuple1, tuple2): return tuple( map( add, tuple1, tuple2))

def get_border_4_lines( center, direction):
    other_axes = get_other_two_axes( direction)

    border1 = [ minus_tuples( minus_tuples( center, other_axes[0]), other_axes[1]),
                minus_tuples(center, other_axes[0]),
                plus_tuples( minus_tuples( center, other_axes[0]), other_axes[1])]
    border2 = [ minus_tuples( plus_tuples(center, other_axes[1]), other_axes[0]),
                plus_tuples(center, other_axes[1]),
                plus_tuples( plus_tuples(center, other_axes[1]), other_axes[0])]
    border3 = [ plus_tuples( plus_tuples(center, other_axes[0]), other_axes[1]),
                plus_tuples(center, other_axes[0]),
                minus_tuples(plus_tuples(center, other_axes[0]), other_axes[1])]
    border4 = [ plus_tuples( minus_tuples(center, other_axes[1]), other_axes[0]),
                minus_tuples(center, other_axes[1]),
                minus_tuples(minus_tuples(center, other_axes[1]), other_axes[0])]
    return other_axes, [border1, border2, border3, border4]

def rotate( center, clockwise, direction):
    other_axes, border_lines = get_border_4_lines( center, direction)
    directions = [ get_inversed_axis( other_axes[0]), other_axes[1],
                   other_axes[0], get_inversed_axis( other_axes[1])]

    if clockwise == '+':
        border_lines.reverse()
        directions.reverse()

    prev_line_state = [cube[ pos[0]][ pos[1]][ pos[2]].state for pos in border_lines[-1]]
    for dir_idx, border_line in enumerate( border_lines):
        temp = [dict(cube[pos[0]][pos[1]][pos[2]].state) for pos in border_lines[ dir_idx]]
        for cell_idx, cell_pos in enumerate( border_line):
            cube[ cell_pos[0]][ cell_pos[1]][ cell_pos[2]].state[ directions[ dir_idx]] = \
                prev_line_state[cell_idx][ directions[dir_idx - 1]]
            if cell_idx > 0:
                cube[ cell_pos[0]][ cell_pos[1]][ cell_pos[2]].state[ direction] = \
                    prev_line_state[cell_idx][ direction]
        prev_line_state = temp

def get_result():
    result = []
    for y in range(3):
        unit = []
        for x in range(3):
            unit.append( cube[x][y][0].state[U])
        result.append( unit)
    return result

def solution( commands):
    global cube

    cube = initialize_cube()
    for command in commands:
        center, clockwise, direction = CENTERS[ command[0]], command[1], DIRECTIONS[ command[0]]
        if command[0] in ('R','B','D'): clockwise = '+' if clockwise == '-' else '-'
        rotate( center, clockwise, direction)

    return get_result()

if __name__ == '__main__':
    test_case = int( input())
    for case_number in range( 1, test_case + 1):
        N, commands = data_in()
        result = solution( commands)
        for line in result: print( ''.join(line))
