op_list = [
    lambda a,b : a+ b,
    lambda a,b : a-b,
    lambda a,b : a * b,
    lambda a,b : a / b if b != 0 else None
]


def solution(N, number):

    cache = [set() for _ in range(0, 9)]
    cache[1].add(N)

    for i in range(2, 9):
        init_num = int(str(N)*i)
        cache[i].add(init_num)

        if init_num == number:
            return i

        for N_cnt in range(1,i):
            for op_cnt in range(4):
                # cache[j]에 있는 모든 값 과 cache[i-j]에 있는 모든 값을 연산해서 넣어줘야 한다.
                for e1 in cache[N_cnt]:
                    for e2 in cache[i-N_cnt]:
                        unit_ans = op_list[op_cnt](e1, e2)

                        if unit_ans is not None:
                            cache[i].add(unit_ans)

                        if unit_ans == number:
                            return i

    return -1
