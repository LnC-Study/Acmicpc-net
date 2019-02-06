from math import sqrt

def data_in():
    return map( int, input().split())

def solution( _diff):
    if _diff == 0 : return 0

    lower = sqrt( _diff)
    if lower == int( lower): return lower * 2 - 1
    return int(lower) * 2 if _diff < int( lower) ** 2 + lower else int(lower) * 2 + 1

if __name__ == '__main__':
    X, Y = data_in()
    ans = solution( abs( X - Y))
    print( int(ans))