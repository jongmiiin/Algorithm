from itertools import permutations

def solution(k, dungeons):
    answer = 0
    for dgs in permutations(dungeons):
        kk = k
        temp = 0
        for dg in dgs:
            if dg[0] <= kk:
                temp += 1
                kk -= dg[1]
        answer = max(temp, answer)
    return answer