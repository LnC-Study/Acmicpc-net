sec = int(input())


def transform(cnt):
    if cnt == 1:
        return 0
    elif cnt == 2:
        return 1

    else:
        if cnt % 2 == 0: # 앞에꺼 다 더하고 + 1
            return 2 * transform(cnt - 1) + 1

        else: # 앞에꺼 다 더함
            return 2*transform(cnt-1) - 1
