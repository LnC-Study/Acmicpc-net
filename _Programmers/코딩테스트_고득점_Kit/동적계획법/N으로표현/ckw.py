op_list = [
    lambda a,b : a+ b,
    lambda a,b : a-b,
    lambda a,b : a * b,
    lambda a,b : a / b if b != 0 else None
]


def solution(N, number):

    cache = [set() for _ in range(0, 9)]
    cache[1].add(N)

    # 1이 되는 값은 이전 셋에 넣어놨다!
    for N_cnt in range(2, 9):
        init_num = int(str(N)*N_cnt)
        cache[N_cnt].add(init_num)

        if init_num == number:
            return N_cnt

        # N번 째를 한다면 1,N-1을 연산 할 경우, 2, N-2을 연산 할 경우 ... N-1, 1 을 연산할 경우 를 고려 해 주어야 한다.
        for case_num in range(1, N_cnt):
            for op_cnt in range(4):
                # cache[j]에 있는 모든 값 과 cache[i-j]에 있는 모든 값을 연산해서 넣어줘야 한다.
                for e1 in cache[case_num]:
                    for e2 in cache[N_cnt-case_num]:
                        unit_ans = op_list[op_cnt](e1, e2)

                        if unit_ans is not None:
                            cache[N_cnt].add(unit_ans)

                        if unit_ans == number:
                            return N_cnt

    return -1
