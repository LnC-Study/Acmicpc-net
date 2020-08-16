BLACK = -1
def put_black_blocks( cols):
    for col in cols:
        for row in range( size):
            if board[row][col] > 0: break
            board[row][col] = BLACK

def get_black_blocks( LD, RU):
    count = 0
    for row in range( LD[0], RU[0] + 1):
        for col in range( LD[1], RU[1] + 1):
            if board[row][col] == BLACK: count +=1
    return count

def remove_block(coords):
    for coord in coords: board[ coord[0]][ coord[1]] = 0

def removable_blocks():
    count, remove_cols, remove_blocks = 0, set(), []

    for block in location:
        LD = ( min( map( lambda x: x[0], location[block])),
               min( map( lambda x: x[1], location[block])))
        RU = ( max( map( lambda x: x[0], location[block])),
               max( map( lambda x: x[1], location[block])))

        if get_black_blocks( LD, RU) == 2 :
            count += 1
            remove_block(location[block])
            remove_blocks.append( block)
            remove_cols = remove_cols | set( range( LD[1], RU[1] + 1))

    for block in remove_blocks: del location[block]

    return count, list(remove_cols)

def do_task():
    answer, count,remove_cols = 0, 1, range(size)
    while count != 0:
        put_black_blocks( remove_cols)
        count, remove_cols = removable_blocks()
        answer += count

    return answer

def get_blocks_location():
    result = {}
    for row in range(size):
        for col in range(size):
            if board[row][col] != 0:
                if board[row][col] in result: result[board[row][col]].append((row, col))
                else: result[board[row][col]] = [(row, col)]
    return result

def solution( data):
    global board, size, location
    board, size = data, len(data)
    location = get_blocks_location()

    return do_task()