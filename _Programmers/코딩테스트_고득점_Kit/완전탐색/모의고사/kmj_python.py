def createSheet(num):
    students=[[1, 2, 3, 4, 5], 
              [2, 1, 2, 3, 2, 4, 2, 5], 
              [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    for i in range(len(students)):
        if num > len(students[i]):
            offset = round(num/len(students[i]))+1
            temp = list(students[i])
            for _ in range(offset):
                students[i].extend(temp)
    return students

def solution(answers):
    answer = []
    scores = [0, 0, 0]
    problems = len(answers)
    # 답안지 생성
    students = createSheet(problems)
    # 채점 시작
    for i in range(problems):
        for j in range(len(students)):
            if students[j][i] == answers[i]:
                scores[j] = scores[j] + 1
    # 1등 뽑기
    max_num = max(scores)
    for i in range(len(students)):
        if scores[i] == max_num:
            answer.append(i+1)
    return answer
