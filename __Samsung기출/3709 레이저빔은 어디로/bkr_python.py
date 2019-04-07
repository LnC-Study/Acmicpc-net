N=int(input())
def getdir(x,y):
    if(x==0):
        direction = 1
    elif (x==n+1):
        direction = 2
    elif(y==0):
        direction = 3
    elif(y==n+1):
        direction = 4
    return direction
def laser_go(x,y,dir):
    if(dir==1):
        x=x+1
    if (dir==2):
        x=x-1
    if dir==3:
        y=y+1
    if dir==4:
        y=y-1
    return x,y

def meet_mirror(dir):
    dirs={ 1:4, 2:3, 3:1,4:2 }
    return dirs[dir]


for _ in range (N):
    n,r = map(int,input().split())
    mirrors = []
    mirrors.append([-2 for _ in range (n+2)])
    for i in range(n):
        list_temp =[-2]
        for _ in range(n):
            list_temp.append(-1)
        list_temp.append(-2)
        mirrors.append(list_temp)
    mirrors.append([-2 for _ in range(n + 2)])

    for _ in range(r):
        x,y = map(int,input().split())
        mirrors[x][y] = 0
    laser_x, laser_y = map(int,input().split())

    #input FINISH
    direction = getdir(laser_x,laser_y)
    went_mirrors=[]

    while(True):
        #print(laser_x,laser_y, direction)
        laser_x,laser_y = laser_go(laser_x,laser_y,direction)
      #  print(laser_x, laser_y, direction)
        if mirrors[laser_x][laser_y] == -2:
            print(laser_x,laser_y) # if found...
            break
        elif mirrors[laser_x][laser_y] == -1:
            continue
        elif mirrors[laser_x][laser_y] > -1 :
            direction=meet_mirror(direction)
            went_mirror = [laser_x,laser_y,direction]
            if went_mirror in went_mirrors:
                print(0,0)
            else:
                went_mirrors.append(went_mirror)
               # print(went_mirrors)