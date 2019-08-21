import sys


def transform(cnt):
    arr = [0, 0, 1] # using index from 1

    if cnt <= 2:
        return arr[cnt]

    for step in range(3,cnt+1):
        if step % 2 == 0:
            arr.append(2*arr[step-1] + 1)
        else:
            arr.append(2*arr[step-1] - 1)

    return arr[cnt]


testCase = sys.stdin.read()
testCase = testCase.split('\n')
testCase.pop()
testCase = map(int, testCase)

for question in testCase:
    print(transform(question))
