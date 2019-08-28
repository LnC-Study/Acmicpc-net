def solution(n):

    # case 1: remove first 2 blocks
    ans_list = [0 for i in range(0, n+1)]

    ans_list[0] = 0
    ans_list[1] = 0
    ans_list[2] = 3
    ans_list[3] = 0

    for i in range(4, n+1):

        if i % 2 == 1:
            ans_list[i] = 0

        else:
            first = ans_list[i-2] * 3
            second = 2 * (sum([ans_list[i-2*j] for j in range(2, int(i/2))]) + 1)
            ans_list[i] = (first + second) % 1000000007

    return ans_list[n]
