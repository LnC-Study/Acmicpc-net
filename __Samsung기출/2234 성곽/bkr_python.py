def check_room():
    for i in range (x):
        for j in range(y):
            if(room_stat[i][j]==-1):
                #print("CHECK ROOM2 : ",i,j)
                return i,j
    return -1,-1
        
def check_dir(x,y):

    num = room[x][y]
    a= num&1
    b= (num&2)>>1
    c= (num&4)>>2
    d= (num&8)>>3
    if(a==0):
        if(room_stat[x][y-1] ==-1):
            queue.append([x, y-1])
    if (b==0):
        if(room_stat[x-1][y] ==-1):
            queue.append([x-1, y])
    if (c==0):
        if(room_stat[x][y+1] ==-1):
            queue.append([x, y+1])
    if (d==0):
        if(room_stat[x+1][y] ==-1):
            queue.append([x+1, y])
    
y, x = map(int, input().split())

room=[]
queue = []
for i in range(x):
    room.append(list(map(int, input().split())))
#print(room)

room_stat=[]
for i in range(x):
    room_stat.append([-1 for j in range(y)])
#print(room_stat)

room_num = 0
find_x, find_y  = 0,0
wide_count=[]
while(True):
    find_x,find_y = check_room()
    if(find_x== -1 and find_y == -1):
        break
    #print(find_x, find_y)
    check_dir(find_x, find_y)
    room_num = room_num +1
    room_stat[find_x][find_y] = room_num
    wide_count.append(0)
    wide_count[room_num-1] = wide_count[room_num-1] + 1
    while(queue):
        find_x,find_y = queue.pop()
        wide_count[room_num-1] = wide_count[room_num-1] + 1
        room_stat[find_x][find_y] = room_num
        check_dir(find_x, find_y)

print(room_num)
max_wide = -1
for i in wide_count:
    if(max_wide < i):
        max_wide = i
print(max_wide)

break_wall_wide=max_wide

for i in range (x):
    for j in range(y-1):
        if(room_stat[i][j] == room_stat[i][j+1]):
            continue;
        now_wide = wide_count[room_stat[i][j]-1]
        next_wide = wide_count[room_stat[i][j+1]-1]
        break_wall_temp = now_wide+ next_wide
        print(break_wall_temp)
        if (break_wall_temp > break_wall_wide):
            break_wall_wide = break_wall_temp

for j in range (y):
    for i in range(x-1):
        if(room_stat[i][j] == room_stat[i+1][j]):
            continue;
        now_wide = wide_count[room_stat[i][j]-1]
        next_wide = wide_count[room_stat[i+1][j]-1]
        break_wall_temp = now_wide+ next_wide
        if (break_wall_temp > break_wall_wide):
            break_wall_wide = break_wall_temp


print(break_wall_wide)
