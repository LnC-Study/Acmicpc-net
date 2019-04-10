def data_in():
    W, H = map(int, input().split())
    P, Q = map(int, input().split())
    T = int(input())

    return W, H, (P, Q), T

def solution(width, height, init_pos, time):
    x_last_pos, x_movement_blocks = (init_pos[0] + time) % width, (init_pos[0] + time) // width
    y_last_pos, y_movement_blocks = (init_pos[1] + time) % height, (init_pos[1] + time) // height

    if x_movement_blocks % 2 == 1: x_last_pos = width - x_last_pos
    if y_movement_blocks % 2 == 1: y_last_pos = height - y_last_pos

    return (x_last_pos, y_last_pos)

if __name__ == '__main__':
    width, height, init_pos, time = data_in()
    ans = solution(width, height, init_pos, time)
    print(f'{ans[0]} {ans[1]}')