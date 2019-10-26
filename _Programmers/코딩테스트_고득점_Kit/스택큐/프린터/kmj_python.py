def solution(priorities, location):
    answer = 0
    key = list(0 for i in range(len(priorities)))
    key[location] = 1
    while True:
        num = priorities.pop(0)
        key_num = key.pop(0)
        if not priorities:
            answer = answer + 1
            break
        if num < max(priorities):
            priorities.append(num)
            key.append(key_num)
        else:
            answer = answer + 1
            if key_num == 1:
                break   
    return answer
