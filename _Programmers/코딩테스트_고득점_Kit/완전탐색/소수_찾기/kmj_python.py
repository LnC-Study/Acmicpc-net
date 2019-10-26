from itertools import permutations
def strToInt(arr):
    num = ""
    for i in arr:
        num = num+i
    return int(num)

def getPrime(arr):
    limit = max(arr)
    primes = list(True for i in range(0, limit+1))
    primes[0] = False
    primes[1] = False
    for i in range(limit+1):
        if not primes[i]:
            continue
        index = i+i
        while index <= limit:
            primes[index] = False
            index = index + i
    return primes

def solution(numbers):
    answer = list()
    numbers = list(numbers)
    
    # 후보군 생성
    for length in range(1, len(numbers)+1):
        temp = set(permutations(numbers, length))
        for case in temp:
            candidate = strToInt(case)
            answer.append(candidate)
    answer = set(answer)
    # 소수 판단
    sum = 0
    primes = getPrime(answer)
    for i in answer:
        if primes[i]:
            print(i)
            sum = sum + 1
    return sum
