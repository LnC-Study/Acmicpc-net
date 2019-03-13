from itertools import accumulate
INF = 999999999

def data_in():
    return int( input()), list( map(int, input().split()))

def dp( start, end):
    if dp_table[ start][end] != INF: return dp_table[start][end]

    sum_in_range = accum_sum[end] - accum_sum[start-1]
    for idx in range( start, end):
        left, right = dp( start, idx), dp( idx+1, end)
        if dp_table[start][end] > left + right + sum_in_range:
            dp_table[start][end] = left + right + sum_in_range

    return dp_table[start][end]

def solution(size, products):
    global dp_table, accum_sum

    # initialize dp table & accumulate sum
    dp_table = [[0 if row == col else INF for col in range(size + 1)] for row in range(size + 1)]
    accum_sum = list(accumulate( products))
    return dp( 1, size)

if __name__ == '__main__':
    test_case = int( input())
    for _ in range( test_case):
        k, products = data_in()
        if k == 1: ans = products[0]
        else :
            products.insert(0, 0)
            ans = solution( k, products)
        print( f'#{_ + 1} {ans}')