def solution(lottos, win_nums):
    answer = [7, 7]
    win_cnt = 0
    zero_cnt = 0
    
    for lotto in lottos:
        if lotto in win_nums:
            win_cnt+=1
        if lotto == 0:
            zero_cnt+=1
    
    for i in range(6,0,-1):
        if win_cnt == i:
            answer[0]-=i
            answer[1]-=i
        if zero_cnt == i:
            answer[0]-=i
    
    if answer[0] == 7:
        answer[0] = 6
    if answer[1] == 7:
        answer[1] = 6
    return answer