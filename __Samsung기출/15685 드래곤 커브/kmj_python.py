def data_in():
    N = int(input())
    arr = list(list(int(i) for i in input().split()) for i in range(N))
    return arr


def dragonCurve(start, offset, generation):
    direction = {0:(1, 0), 1: (0, -1), 2: (-1, 0), 3: (0, 1)}
    curves = [ start, (start[0]+direction[offset][0], start[1]+direction[offset][1]) ]

    for _ in range(generation):
        end = curves[len(curves)-1] # 마지막 점을 기준으로 회전
        new_curves = list()
        for i in range(len(curves)-1):  # 마지막 점을 제외하고 회전변환 적용
            index = len(curves)-2-i
            x = -curves[index][1] + end[0] + end[1]
            y = curves[index][0] - end[0] + end[1]
            new_curves.append((x, y))
        curves.extend(new_curves)
    return curves


def findSquares(arr):
    arr = list(set(arr))
    arr = sorted(arr)

    cnt = 0
    for i in range(1, len(arr)):
        if arr[i-1][0] == arr[i][0] and (arr[i][1] - arr[i-1][1] == 1):
            # 가능성 조사
            if ((arr[i-1][0]+1, arr[i-1][1]) in arr) and ((arr[i][0]+1, arr[i][1]) in arr):
                cnt = cnt + 1
    return cnt


def solution(curves):
    vertex = list()
    for row in curves:
        temp = dragonCurve((row[0], row[1]), row[2], row[3])
        vertex.extend(temp)
    return findSquares(vertex)


if __name__ == "__main__":
    arr = data_in()
    answer = solution(arr)
    print(answer)

