dwarf, color = input().split(' ')
dwarf = int(dwarf)
color = int(color)

colorList = input().split(' ')
colorList = list(map(int, colorList))

picture = int(input())
answer = ''


def counting(start, end):
    max = 0
    num = 0
    for c in range(1, color+1):
        cur = colorList[start:end].count(c)
        if max < cur:
            max = cur
            num = c

    return num, max


for cnt in range(picture):
    start, end = input().split(' ')
    start = int(start)-1
    end = int(end)

    maxColor, maxValue = counting(start, end)

    if maxValue > (end-start)//2:
        answer += 'yes %d\n' % maxColor

    else:
        answer += 'no\n'

print(answer)
