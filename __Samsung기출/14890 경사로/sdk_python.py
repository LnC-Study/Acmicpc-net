VERTICAL, HORIZONTAL = (1,0), (0,1)

def data_in():
    size, length = map( int, input().split())
    return size, length, [ list( map( int, input().split())) for _ in range( size)]

def is_in( row, col):
    return 0 <= row < size and 0 <= col < size

def put_slope_way( way):
    if way[1] - way[2] * length < length: return False
    else: way[2] += 1

    return True

def is_able_to_go( row, col, direction):
    current, count = board[ row][col], 1
    path = [ [current, count, 0]]

    for idx in range( 1, size):
        row, col = row + direction[0], col + direction[1]
        if path[-1][0] == board[ row][ col]: path[-1][1] += 1
        else: path.append( [board[ row][ col], 1, 0])

    prev = path[0]
    for current in path[1:]:
        if abs( prev[0] - current[0]) != 1 : return False

        if prev[0] < current[0] and not put_slope_way( prev): return False
        if prev[0] > current[0] and not put_slope_way( current): return False

        prev = current

    return True

def solution():
    count = 0
    for idx in range( size):
        if is_able_to_go( idx, 0, HORIZONTAL): count += 1
        if is_able_to_go( 0, idx, VERTICAL): count +=1

    return count
if __name__ == '__main__':
    global size, length, board

    size, length, board = data_in()
    ans = solution()

    print( ans)