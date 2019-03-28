#https://www.acmicpc.net/problem/14499

N, M, x, y, K = map(int, input().split())

Map = [list(map(int, input().split())) for _ in range(N)]

command = list(map(int, input().split()))

print(command)

dice = [-1, 0, 0, 0, 0, 0, 0]

for i in range(K):
    if command[i] == 1:
        if y+1 < M :
            y += 1
            #print(command[i], y, x)
            if Map[x][y] != 0:
                dice[1], dice[3], dice[4], dice[6] = dice[4], dice[1], dice[6], dice[3]
                dice[6] = Map[x][y]
                Map[x][y] = 0
            elif Map[x][y] == 0:
                dice[1], dice[3], dice[4], dice[6] = dice[4], dice[1], dice[6], dice[3]
                Map[x][y] = dice[6]
            print(dice[1])
    elif command[i] == 2:
        if y-1 >= 0:
            y -= 1
            #print(command[i], y, x)
            if Map[x][y] != 0:
                dice[1], dice[3], dice[4], dice[6] = dice[3], dice[6], dice[1], dice[4]
                dice[6] = Map[x][y]
                Map[x][y] = 0
            elif Map[x][y] == 0:
                dice[1], dice[3], dice[4], dice[6] = dice[3], dice[6], dice[1], dice[4]
                Map[x][y] = dice[6]
            print(dice[1])
    elif command[i] == 3:
        if x-1 >= 0 :
            x -= 1
            #print(command[i], y, x)
            if Map[x][y] != 0:
                dice[1], dice[2], dice[5], dice[6] = dice[5], dice[1], dice[6], dice[2]
                dice[6] = Map[x][y]
                Map[x][y] = 0
            elif Map[x][y] == 0:
                dice[1], dice[2], dice[5], dice[6] = dice[5], dice[1], dice[6], dice[2]
                Map[x][y] = dice[6]
            print(dice[1])
    elif command[i] == 4:
        if x+1 < N :
            x += 1
            #print(command[i], y, x)
            if Map[x][y] != 0:
                dice[1], dice[2], dice[5], dice[6] = dice[2], dice[6], dice[1], dice[5]
                dice[6] = Map[x][y]
                Map[x][y] = 0
            elif Map[x][y] == 0:
                dice[1], dice[2], dice[5], dice[6] = dice[2], dice[6], dice[1], dice[5]
                Map[x][y] = dice[6]
            print(dice[1])
