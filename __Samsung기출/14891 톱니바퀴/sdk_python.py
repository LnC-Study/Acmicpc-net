CLOCKWISE, COUNTER_CLOCKWISE = 1, -1
LEFT, RIGHT, N, S = -1, 1, '0', '1'

def data_in():
    return [ input() for _ in range(4)]

def rotate( gear, direction):
    if direction == CLOCKWISE:
        temp = gear[-1]
        gear = temp + gear[:-1]
    elif direction == COUNTER_CLOCKWISE:
        temp = gear[0]
        gear = gear[1:] + temp
    else: pass

    return gear

def get_rotate_dirs( gears, start, progress_direction, init_clock_direction):
    global rotate_dirs

    prev, current, clock_direction = start, start + progress_direction, init_clock_direction
    while 0 <= current < 4:
        if progress_direction == LEFT: abut_left,  abut_right = gears[ current][2], gears[ prev][-2]
        else: abut_left, abut_right = gears[ prev][2], gears[ current][-2]

        if abut_left == abut_right: break

        clock_direction = -clock_direction
        rotate_dirs[ current] = clock_direction
        prev, current = current, current + progress_direction

def do_task( gears, target, init_clock_direction):
    global rotate_dirs

    rotate_dirs = [ 0 for _ in range(4)]
    rotate_dirs[ target] = init_clock_direction

    get_rotate_dirs( gears, target, LEFT, init_clock_direction)
    get_rotate_dirs( gears, target, RIGHT, init_clock_direction)

    for idx, dir in enumerate( rotate_dirs):
        gears[idx] = rotate( gears[idx], dir)

def get_score( gears):
    return sum( map( lambda x: 2 ** x[0] if x[1][0] == S else 0, enumerate(gears)))

def solution( gears):
    cmd_numbers = int( input())
    for _ in range( cmd_numbers):
        target, init_clock_direction = map(int, input().split())
        do_task(gears, target - 1, init_clock_direction)

    return get_score( gears)

if __name__ == '__main__':
    gears = data_in()
    ans = solution( gears)
    print( ans)