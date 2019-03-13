from copy import deepcopy

U, R, D, L = (-1,0), (0,1), (1,0), (0,-1)
CCTV_DIRS = {
    1: [[U],[R],[D],[L]],
    2: [[L, R], [U, D]],
    3: [[U, R], [R, D], [D, L], [L, U]],
    4: [[U, R, D], [R, D, L], [D, L, U], [L, U, R]],
    5: [[U, R, D, L]]
}
answer = 9999

def data_in():
    N, M = map( int, input().split())
    return N, M, [ list( map( int, input().split())) for _ in range( N)]

def get_board_state():
    result, blanks = [], 0
    for row in range( height):
        for col in range( width):
            if 1 <= init_board[ row][ col] <= 5: result.append((row, col))
            elif init_board[row][col] == 0: blanks += 1

    return result, blanks

def is_able_to_go( row, col):
    return 0 <= row < height and 0 <= col < width and init_board[row][col] != 6

def get_blanks():
    board, blanks = deepcopy( init_board), init_blanks
    for idx in range( cctv_numbers):
        for dir in selected[ idx]:
            row, col = cctv_pos_list[ idx]
            while is_able_to_go( row, col):
                if board[row][col] == 0:
                    board[row][col] = 1
                    blanks -= 1
                row, col = row + dir[0], col + dir[1]

    return blanks

def brute_force( idx):
    global answer
    if idx == cctv_numbers:
        answer = min( answer, get_blanks())
        return

    cctv_pos = cctv_pos_list[ idx]
    cctv = init_board[ cctv_pos[0]][ cctv_pos[1]]

    for dirs in CCTV_DIRS[ cctv]:
        selected[ idx] = dirs
        brute_force( idx + 1)

def solve():
    global cctv_numbers, cctv_pos_list, selected, init_blanks

    cctv_pos_list, init_blanks = get_board_state()
    cctv_numbers = len( cctv_pos_list)
    selected = [None for _ in range( cctv_numbers)]

    brute_force( 0)

if __name__ == '__main__':
    global height, width, init_board
    height, width, init_board = data_in()
    solve()

    print( answer)