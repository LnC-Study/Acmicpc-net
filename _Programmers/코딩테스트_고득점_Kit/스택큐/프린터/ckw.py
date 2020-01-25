def solution(priorities, location):
    priority_list = list(priorities)
    priority_list.sort()

    print_len = 1

    while True:
        max_num = priority_list[-1]
        max_idx = priorities.index(max_num)

        if max_idx == location:
            return print_len

        priority_list.remove(max_num)

        if max_idx == len(priority_list):
            priorities = priorities[0:-1]
        else:
            priorities = priorities[max_idx + 1:] + priorities[0 : max_idx]

        print_len += 1
        origin_location = location
        location -= max_idx + 1

        if location < 0:
            location = len(priorities) - max_idx + origin_location
