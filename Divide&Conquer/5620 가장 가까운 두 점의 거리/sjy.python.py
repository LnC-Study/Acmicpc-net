_N = int(input())

points = []
distance = []
for cnt in range(_N):
    points.append(list(map(int, input().split(' '))))

for i in range(0, _N-1):
    for j in range(i+1, _N):
        sub = [points[j][0] - points[i][0], points[j][1] - points[i][1]]
        distance.append(abs(sub[0])**2 + abs(sub[1])**2)

print(min(distance))
