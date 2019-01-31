import sys

N = int(input())
K = int(input())

mod = 1000000003

if K>N/2:
    print(0)
    sys.exit(1)
    
elif K == N/2:
    print(2)
    sys.exit(1)

arr = [[0 for n in range(K+1)] for k in range(N+1)]

for i in range(1, N+1):
    arr[i][1] = i

for i in range(2, N+1):
    for j in range(2, K+1):
        arr[i][j] = (arr[i-2][j-1]+arr[i-1][j])%mod

result = (arr[N-3][K-1]+arr[N-1][K])%mod

print(result)
