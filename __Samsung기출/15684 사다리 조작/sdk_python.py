from itertools import combinations

def data_in():
    N, M, H = map( int, input().split())
    return N, M, H, [ tuple(map( int, input().split())) for _ in range( M)]

def down( idx):
    global connected

    current_vert, current_height = idx, 1
    while current_height <= height:
        if current_vert in connected and \
                current_height in connected[ current_vert]: current_vert += 1
        elif current_vert > 0 and \
                current_vert - 1 in connected and \
                current_height in connected[ current_vert - 1]: current_vert -= 1

        current_height += 1

    return current_vert

def is_ok():
    for idx in range( vertical_lines):
        if down( idx) != idx:
            return False

    return True

def transform_connected():
    result = {}
    for line_number in range( vertical_lines): result[ line_number] = []
    for height, left in connected: result[left-1].append( height)

    return result

def get_rest_horizon_lines():
    result = []
    for col in range( vertical_lines - 1):
        for row in range( 1, height + 1):
            if row not in connected[ col]: result.append( (col, row))

    return result

def do_task( picks, rest_horizon_lines):
    global connected

    new_horizon_lines = combinations( rest_horizon_lines, picks)
    for line_set in new_horizon_lines:
        for line in line_set: connected[ line[0]].append( line[1])
        if is_ok(): return True
        for line in line_set: connected[ line[0]].remove( line[1])

    return False

def solution():
    global connected

    connected = transform_connected()
    rest_horizon_lines = get_rest_horizon_lines()
    if is_ok(): return 0

    for ans in range( 1, 4):
        if do_task( ans, rest_horizon_lines): return ans

    return -1

if __name__ == '__main__':
    global vertical_lines, height, connected

    vertical_lines, horizontal_lines, height, connected = data_in()
    ans = solution()
    print( ans)