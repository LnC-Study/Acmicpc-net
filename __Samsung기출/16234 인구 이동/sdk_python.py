def data_in():
    N, L, R = map( int, input().split())
    return N, L, R, [ list( map(int, input().split())) for _ in range(N)]

def is_in( row, col):
    return 0 <= row < size and 0 <= col < size

DIRS = [ (-1,0), (1,0), (0,1), (0,-1)]

def get_unions( row, col):
    nations, populations = [ (row, col)], population_board[ row][col]
    queue = [(row, col)]
    visited[ row][col] = True
    while len( queue) > 0:
        row, col = queue[0][0], queue[0][1]; queue.pop(0)
        for dir in DIRS:
            next_row, next_col = row + dir[0], col + dir[1]
            if not is_in( next_row, next_col): continue

            population_diff = abs(population_board[ next_row][ next_col] - population_board[ row][col])
            if not visited[ next_row][ next_col] and lower <= population_diff <= upper:
                nations.append( (next_row, next_col))
                populations += population_board[ next_row][ next_col]
                visited[ next_row][next_col] = True
                queue.append( (next_row, next_col))
    return nations, populations

def uni(nations, total_population):
    population = int(total_population / len( nations))
    for nation in nations:
        population_board[ nation[0]][ nation[1]] = population

def initialize_visited():
    return [[False for _ in range(size)] for __ in range(size)]

def do_mediate():
    global visited
    flag = False
    visited = initialize_visited()

    for row in range( size):
        for col in range( size):
            if not visited[ row][col]:
                union_nations, total_population = get_unions( row, col)
                if len( union_nations) > 1:
                    uni(union_nations, total_population)
                    flag = True

    return flag

def solution():
    count = 0
    while do_mediate(): count += 1
    return count

if __name__ == '__main__':
    global size, lower, upper, population_board

    size, lower, upper, population_board = data_in()
    answer = solution()

    print( answer)