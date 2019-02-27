def data_in():
    parts = list(int(i) for i in input().split())
    return parts


def cal_sum(parts, i, j):
    total_sum = 0
    for idx in range(i, j+1):
        total_sum = total_sum + parts[idx]
    return total_sum


def initialize_list(parts):
    INF = 987654321
    n = len(parts)
    cost = list(list(0 for i in range(n)) for i in range(n))
    for i in range(n):
        for j in range(n):
            if i == j:
                cost[i][j] = parts[i]
            else:
                if j - i == 1:
                    cost[i][j] = parts[i] + parts[j]
                else:
                    cost[i][j] = INF
    sum = list(list(0 for i in range(n)) for i in range(n))
    for i in range(n):
        for j in range(i, n):
            sum[i][j] = cal_sum(parts, i, j)

    return cost, sum


def solution(cost, sum):
    n = len(cost[0])
    for offset in range(2, n):
        for i in range(n-offset):
            temp = 987654321
            for k in range(i+1, i+offset):
                temp = min(temp, cost[i][k] + cost[k+1][i+offset] + sum[i][i+offset])
            cost[i][i+offset] = min(temp, sum[i][i+offset] + cost[i+1][i+offset], sum[i][i+offset] + cost[i][i+offset-1])

    return cost[0][n-1]


if __name__ == '__main__':
    cnt = int(input())
    results = list()
    for i in range(cnt):
        n = input()
        cost, sum = initialize_list(data_in())
        result = solution(cost, sum)
        results.append(result)

    for i in range(len(results)):
        print('#%d %d' % (i + 1, results[i]))