from itertools import permutations
def isPossible(key, case):
    key = list(key)
    num = list(map(int, list(str(case[0]))))
    #strike판단
    strikes = 0
    for i in range(3):
        if key[i] == num[i]:
            strikes = strikes + 1
    #ball판단
    balls = 0
    for i in range(3):
        if key[i] in num:
            balls = balls + 1
    
    balls = balls - strikes
    if strikes == case[1] and balls == case[2]:
        return True
    return False

def solution(baseball):
    answer = list(i for i in permutations(list(i for i in range(1, 10)), 3))
    for case in baseball:
        temp = list()
        for candidate in answer:
            if isPossible(candidate, case):
                temp.append(candidate)
        answer = temp
    return len(answer)
