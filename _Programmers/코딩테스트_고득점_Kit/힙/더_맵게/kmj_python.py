from heapq import *

def mix(a, b):
    return a+(b*2)

def solution(scoville, K):
    answer = 0
    heap = list(scoville)
    # heap제작
    heapify(heap)
    while True:
        first = heappop(heap)
        if first >= K: 
            break
        if len(heap) == 0:
            return -1
        second = heappop(heap)
        new_food = mix(first, second)
        heappush(heap, new_food)
        answer = answer + 1
    return answer
