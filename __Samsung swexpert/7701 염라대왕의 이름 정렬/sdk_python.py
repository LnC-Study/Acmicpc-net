from functools import reduce
from itertools import groupby

def data_in():
    N = int(input())
    return N, set([input().strip() for _ in range(N)])

def solution(names):
    mapped = list(map(lambda x: (len(x), [x]), names))
    reduced = [reduce(lambda tup1, tup2: (tup1[0], tup1[1] + tup2[1]), group) \
               for _, group in groupby(sorted(mapped), key=lambda x: x[0])]
    return reduced

if __name__ == '__main__':
    test_case = int(input())
    for case_number in range(1, test_case + 1):
        _, names = data_in()
        mr_names = solution(names)

        print(f'#{case_number}')
        for _, names_same_length in mr_names:
            for name in sorted(names_same_length):
                print(name)