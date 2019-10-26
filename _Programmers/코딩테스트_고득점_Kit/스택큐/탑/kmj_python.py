def solution(heights):
    stack = [0] # heights의 index
    result = [0]

    for i in range(1, len(heights)):
        while stack:
            topIdx = len(stack)-1
            index = stack[topIdx]
            if heights[i] < heights[index]:
                result.append(index+1)
                break
            stack.pop()
        if len(stack) == 0:
            result.append(0)
        stack.append(i)

    return result
