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
    answer = 1
    for kind in closet:
        answer = answer * (len(closet[kind]) + 1) 
    return answer - 1
