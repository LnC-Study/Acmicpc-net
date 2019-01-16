d = int(input())
n = 9
queue = [0,1,2,3,4,5,6,7,8,9]

if d<=n:
    print(queue[d])
else:
    while n<d:
        if not queue:
            ans = -1
            break
        number = queue.pop(0)
        digit = str(number)
        digit = digit[-1]
        digit = int(digit)
        for i in range(0,digit):
            queue.append(number*10 + i)
            n = n+1
            if n==d:
                ans = number*10 + i
                break
    print(ans)
