def get_left_average(budgets, M, i):
    left_average = int((M - sum(budgets[:i])) / len(budgets[i:]))
    return left_average


def solution(budgets: list, M: int):
    budgets.sort()

    if M > sum(budgets):
        return budgets[-1]

    start = 0
    end = len(budgets) - 1

    i = int((start + end)/2)

    left = start
    right = end

    while True:

        left_average = get_left_average(budgets, M, i)

        if abs(left - right) == 1:
            return max(get_left_average(budgets, M, left),get_left_average(budgets, M, right))

        elif left_average > budgets[i]:
            left = i
            i = int((i + right)/2)

        elif left_average < budgets[i]:
            right = i
            i = int((left + i) / 2)

        else:
            return left_average

print(solution([120, 110, 140, 150],	485))
