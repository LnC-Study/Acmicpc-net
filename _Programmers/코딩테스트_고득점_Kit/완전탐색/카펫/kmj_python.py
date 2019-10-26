def solution(brown, red):
    answer = []
    sum = round((brown+4)/2)
    for row in range(1, sum):
        col = sum-row
        if row*col == brown+red:
            answer = [row, col]
            break
    if answer[1] > answer[0]:
        return [answer[1], answer[0]]
    return answer
