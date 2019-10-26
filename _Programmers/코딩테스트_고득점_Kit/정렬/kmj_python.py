from heapq import *
def solution(array, commands):
    answer = []
    for cmd in commands:
        heap = list()
        for i in range(cmd[0]-1, cmd[1]):
            heappush(heap, array[i])
        for i in range(cmd[2]):
            temp = heappop(heap)
        answer.append(temp)
    return answer
