def data_in():
    N, M = map( int, input().split())
    return N, M, [ list( map( int, input().split())) for _ in range( N)]

def get_house_location( size, city_map) -> list:
    result = []
    for row in range( size):
        for col in range( size):
            if city_map[row][col] : result.append( (row, col))

    return result

def get_profit( service_center, service_size, cost) -> int:
    profit, receiver = -( service_size ** 2 + (service_size-1) ** 2), 0
    for house in house_location:
        # check that a house can receive the service from center
        distance = abs(house[0] - service_center[0]) + \
                   abs(house[1] - service_center[1]) + 1
        if distance <= service_size:
            profit += cost
            receiver += 1

    return receiver if profit >= 0 else 0

def solution( size, cost, city_map) -> int:
    global house_location
    house_location = get_house_location( size, city_map)

    answer = -1
    for service_size in range( 1, size * 2):
        for row in range( size):
            for col in range( size):
                answer = max( answer, get_profit( (row, col), service_size, cost))

    return answer

if __name__ == '__main__':
    test_case = int( input())
    for number in range( 1, test_case + 1):
        size, cost, city_map = data_in()
        answer = solution( size, cost, city_map)
        print( f'#{number} {answer}')