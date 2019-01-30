MOD = 1000000003

def data_in():
    return int(input()), int(input())

def get_dp_value(_size, _pick):
    dp = [[0 for _ in range( _size + 1)] for __ in range( _pick + 1)]

    for col in range( _size + 1):
        dp[1][col] = col

    for row in range(2, _pick + 1):
        for col in range( row * 2 - 1, _size + 1):
            dp[row][col] = (dp[row - 1][col - 2] + dp[row][col - 1]) % MOD

    return dp[ _pick][ _size]

def solution( _N, _K):
    if _K > _N / 2: return 0
    if _K == 1 : return _N

    # left(N - 1,K) + right(N - 1,K) - mid(N-2,K)
    return get_dp_value( _N - 1, _K) * 2 - get_dp_value( _N-2, _K)

if __name__ == '__main__':
    N, K = data_in()
    ans = solution( N, K)
    print( ans % MOD)