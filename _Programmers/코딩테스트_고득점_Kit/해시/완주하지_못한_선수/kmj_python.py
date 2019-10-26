from operator import itemgetter
def solution(participant, completion):
    answer = ''
    name_list = dict()
    for name in participant:
        if name in name_list:
            name_list[name] = name_list[name] +1
        else:
            name_list[name] = 0
    for name in completion:
        name_list[name]  = name_list[name] - 1
    name_list = list(map(list,name_list.items()))
    min = name_list[0]
    name_list = sorted(name_list, key=itemgetter(1), reverse = True)
    return name_list[0][0]
