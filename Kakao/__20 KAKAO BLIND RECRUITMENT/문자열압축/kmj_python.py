def solution(w):
    if len(w) == 0:
        return ""

    u, v, isValidate = check(w)
    if isValidate:
        return "".join(u) + solution(v)
    else:
        temp = list(u[1: len(u) - 1])
        return "(" + solution(v) + ")" + convert(temp)


def check(w):
    stack = []
    index = len(w)
    isValidate = False
    left = 0
    right = 0
    for i in range(len(w)):
        if w[i] == '(':
            left = left + 1
            stack.append('(')
        else:
            right = right + 1
            if len(stack) > 0:
                stack.pop()

        if left == right:
            index = i
            break
    if len(stack) == 0:
        isValidate = True
    return w[:index+1], w[index+1:], isValidate


def convert(p):
    for i in range(len(p)):
        if p[i] == '(':
            p[i] = ')'
        else:
            p[i] = '('
    return "".join(p)
