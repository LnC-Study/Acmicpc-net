# 17140 이차원 배열과 연산 (정답율 43.566%)
import operator

def data_in():
    a, b, c = map(int, input().split())
    arr = list(list(map(int, input().split())) for i in range(3))
    return a, b, c, arr


def calculate_row(arr):
    # 1. 각 행별 dict 생성
    max_row_size = 0
    for row_index in range(len(arr)):
        sort_ref = dict()

        for element in arr[row_index]:
            if element in sort_ref:
                sort_ref[element] = sort_ref[element] + 1
            elif element != 0:
                sort_ref[element] = 1

        # 2. 정렬 연산 후 새로운 배열 생성
        temp_list = list(sorted(sort_ref.items(), key=operator.itemgetter(1, 0)))   # sort by value
        new_row = list()
        for tuple in temp_list:
            new_row.append(tuple[0])
            new_row.append(tuple[1])
        arr[row_index] = new_row

        if len(arr[row_index]) > max_row_size:
            max_row_size = len(arr[row_index])

    # 3. Max 행 길이 기준으로 0 추가
    for row_index in range(len(arr)):
        if len(arr[row_index]) < max_row_size:
            for _ in range(max_row_size-len(arr[row_index])):
                arr[row_index].append(0)
    return arr


def calculate_col(arr):
    # transpose 처리 먼저 필요
    processed_arr = [list(x) for x in zip(*arr)]
    # 한번더 transpose
    return [list(x) for x in zip(*calculate_row(processed_arr))]


def solution(r, c, k, arr):
    cnt = 0

    while True:
        row = len(arr)
        col = len(arr[0])

        # 종료 검사
        if row > r-1 and col > c-1:
            if arr[r - 1][c - 1] == k:
                break

        if row >= col:
            arr = calculate_row(arr)
        else:
            arr = calculate_col(arr)

        cnt = cnt + 1
        if cnt > 100:
            cnt = -1
            break
    return cnt


if __name__ == "__main__":
    r, c, k, input_arr = data_in()
    result = solution(r, c, k, input_arr)
    print(result)

