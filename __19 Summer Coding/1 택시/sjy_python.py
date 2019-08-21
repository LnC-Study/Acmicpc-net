# cheated sunny's..TT

people = list(map(int, input().split(' ')))


def sol(groups):
    taxi = 0
    head = 0
    tail = len(groups)-1

    while head <= tail:
        sum = groups[head] + groups[tail]
        if sum == 4:
            head += 1
            tail -= 1

        elif sum < 4:
            head += 1

        else:
            tail -= 1

        taxi += 1

    return taxi


print(sol(sorted(people)))

