N, M = list(map(int, input().split(' ')))
house = []
chicken = []
picked = []
dis_each_home = []

for row in range(N):
    tmp = list(map(int, input().split(' ')))
    for col in range(N):
        what = tmp[col]
        if what == 1:
            house.append((row, col))
        elif what == 2:
            chicken.append((row, col))


def comb(total, toPick): # 전체 치킨집에서 몇개를 뽑는다 --> chicken 배열에서 M개를 뽑음(인덱스)
    global city, house, chicken, chickenDistance
    if toPick == 0:
        tmp = [999 for _ in range(len(house))]
        for idx in picked:
            for h_idx in range(len(house)):
                cur = chicken[idx] # idx번째 치킨집의 위치
                val = abs(house[h_idx][0] - cur[0]) + abs(house[h_idx][1] - cur[1])
                if tmp[h_idx] > val:
                    tmp[h_idx] = val
            dis_each_home.append(tmp)

    if len(picked) == 0:
        smallest = 0

    else:   smallest = picked[-1] + 1

    for next in range(smallest, total):
        picked.append(next)
        comb(total, toPick-1)
        picked.pop()


comb(len(chicken), M)

min = 999
for each in dis_each_home:
    if sum(each) < min:
        min = sum(each)

print(min)

