# 1669: 멍멍이 쓰다듬기

# x: height of monkey
# y: height of dog
(x, y) = map(int, input().split())
diff = abs(x - y)

if diff == 0:
    day = 0
else:
    if diff == 1:
        day = 1
    else:
        day = 2
        offset = 1
        for i in range(2, diff + 1):
            if offset == 0:
                offset = day - 1
                day = day + 1
            else:
                offset = offset - 1

print(day)
