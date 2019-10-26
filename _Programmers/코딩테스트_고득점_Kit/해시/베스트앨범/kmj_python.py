from operator import itemgetter
from heapq import *
def solution(genres, plays):
    answer = []
    # 장르별 재생횟수합(내림차순)으로 정렬
    ref = dict()
    for i in range(len(genres)):
        if genres[i] in ref:
            ref[genres[i]][0] = ref[genres[i]][0] + plays[i]
            ref[genres[i]][1].append(i)
        else:
            ref[genres[i]] = [plays[i], [i]]
    ref = sorted(ref.items(), key=itemgetter(1), reverse=True)
    # 각 노래별 정렬 후 택함.
    for genre in ref:
        heap = list()
        songs = genre[1][1]
        for song in songs:
            heappush(heap, (-plays[song], song))
        # 때에 따라 2번 뽑음.
        answer.append(heappop(heap)[1])
        if len(heap) > 0:
            answer.append(heappop(heap)[1])
    return answer
