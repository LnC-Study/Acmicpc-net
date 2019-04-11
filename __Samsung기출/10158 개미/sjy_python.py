w, h = list(map(int, input().split(' ')))
cPos, rPos = list(map(int, input().split(' ')))
time = int(input())
rPos, cPos = h - abs(h - (rPos + time) % (2*h)), w - abs(w - (cPos + time) % (2*w))

print(cPos, rPos)

