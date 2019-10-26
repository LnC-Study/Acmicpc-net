from itertools import combinations
def solution(clothes):
    # 종류별 분류
    closet = dict()
    for cloth in clothes:
        name, kind = cloth[0], cloth[1]
        if kind in closet:
            closet[kind].append(name)
        else:
            closet[kind] = [name]
    # 경우의 수 조사
    testcase = list()
    for i in range(1, len(closet.keys())+1):
        for case in combinations(closet.keys(), i):
            testcase.append(list(case))
    answer = 0
    for case in testcase:
        temp = 1
        for kind in case:
            temp = temp * len(closet[kind])
        answer = answer + temp
    return answer
