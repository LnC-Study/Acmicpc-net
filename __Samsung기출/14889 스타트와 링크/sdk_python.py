from itertools import combinations, permutations
INF = 987564321

def data_in():
    size = int( input())
    return size, [ list( map( int, input().split())) for _ in range( size)]

def get_team_score( team):
    pos_list = permutations( team, 2)
    return sum( board[pos[0]][ pos[1]] for pos in pos_list)

def solution( size):
    ans = INF
    for start_team in combinations( range( size), size // 2):
        link_team = set( range( size)) - set( start_team)
        start_team_score, link_team_score = get_team_score( start_team), get_team_score( link_team)
        ans = min( ans, abs( start_team_score - link_team_score))

    return ans

if __name__ == '__main__':
    global board

    size, board = data_in()
    ans = solution( size)

    print( ans)