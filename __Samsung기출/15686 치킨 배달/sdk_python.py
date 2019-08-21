from itertools import combinations
INF = 987654321

def data_in():
    N, M = map( int, input().split())
    return N, M, [ list( map( int, input().split())) for _ in range( N)]

def get_building_pos():
    houses, restaurants = [], []
    for row in range( size):
        for col in range( size):
            if board[ row][col] == 1: houses.append( (row, col))
            elif board[ row][col] == 2 : restaurants.append( (row, col))

    return houses, restaurants

def get_distance( pos1, pos2):
    return abs( pos1[0] - pos2[0]) + abs( pos1[1] - pos2[1])

def get_chicken_distance( houses, picked):
    chicken_distance = 0

    for house in houses:
        current_distance = INF
        for restaurant in picked:
            current_distance = min( current_distance, get_distance( house, restaurant))

        chicken_distance += current_distance

    return chicken_distance

def solution( size, picks, board):
    ans = INF
    houses, restaurants = get_building_pos()
    picked_list = combinations( restaurants, picks)
    for picked in picked_list:
        ans = min( ans, get_chicken_distance( houses, picked))

    return ans

if __name__ == '__main__':
    global board, size, picks

    size, picks, board = data_in()
    ans = solution( size, picks, board)
    print( ans)