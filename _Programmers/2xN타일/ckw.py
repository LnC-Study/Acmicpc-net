def solution(n):

    ans_list = [0 for i in range(0,n+1)]

    ans_list[0] = 1
    ans_list[1] = 1
    ans_list[2] = 2

    for i in range(3, n+1):
        ans_list[i] = (ans_list[i-1] + ans_list[i-2]) % 1000000007

    return ans_list[n]
