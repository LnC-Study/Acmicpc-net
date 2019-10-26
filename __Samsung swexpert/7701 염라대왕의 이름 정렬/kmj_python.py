from queue import PriorityQueue

def data_in():
    N = int(input())
    arr = list(input() for _ in range(N))
    return arr

def solution(arr):
    answer = list()
    # 중복 제거
    processed_arr = list(set(arr))
    
    # 우선순위 큐에 삽입
    queue = PriorityQueue(maxsize=len(processed_arr))
    for word in processed_arr:
        queue.put((len(word), word))
        
    # 우선순위 큐에서 제거 -> 길이 짧은순, 사전순으로 제거됨.
    for _ in range(len(processed_arr)):
        item = queue.get()[1]
        answer.append(item)
    return answer

if __name__ == "__main__":
    T = int(input())
    for test_case in range(1, T + 1):
        arr = data_in()
        answer = solution(arr)
        #출력
        print("#%d" %test_case)
        for word in answer:
            print(word)
