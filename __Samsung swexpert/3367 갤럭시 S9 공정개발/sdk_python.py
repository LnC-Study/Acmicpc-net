from itertools import accumulate
INF = 999999999

def data_in():
    return int( input()), list( map(int, input().split()))

def solution( size, products) -> int :
    # initialize dp table & accumulate sum
    dp_table = [[0 for _ in range(size + 1)] for __ in range(size + 1)]
    knuth = [[col if row == col - 1 else 0 for col in range(size + 1)] for row in range(size + 1)]
    accum_sum, current = list( accumulate( products)), 0

    for step in range(2, size+1):
        for row in range( 0, size-step+1):
            col = row + step
            sum_in_range = accum_sum[col] - accum_sum[row]
            dp_table[row][col] = INF
            for div in range( knuth[row][col-1], knuth[row+1][col] + 1):
                left, right = dp_table[row][div], dp_table[div][col]
                if dp_table[row][col] > left + right + sum_in_range:
                    dp_table[row][col] = left + right + sum_in_range
                    knuth[row][col] = div

    return dp_table[0][size]

if __name__ == '__main__':
    test_case = int( input())
    for _ in range( test_case):
        k, products = data_in()
        if k == 1: ans = 0
        else :
            products.insert(0, 0)
            ans = solution( k, products)
        print( f'#{_ + 1} {ans}')