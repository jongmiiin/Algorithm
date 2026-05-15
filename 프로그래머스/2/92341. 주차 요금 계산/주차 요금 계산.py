from math import ceil

def change_min(time):
    h, m = time.split(':')
    mins = int(h)*60 + int(m)
    return mins

def cal_fee(fees, park_min):
    result = []
    park_num = sorted(park_min)
    for key in park_num:
        sum = fees[1] + ((ceil((park_min[key]-fees[0])/fees[2])*fees[3]) if (park_min[key]-fees[0])>0 else 0)
        result.append(sum)
    
    return result
    

def solution(fees, records):
    park_min = dict() # 몇분 주차했는지
    park_rec = dict() # 입차 시간
    
    for record in records:
        time, num, stat = record.split(' ')
        mins = change_min(time)
        if stat == 'IN':
            if num not in park_rec:
                park_rec[num] = mins
                park_min[num] = 0
            else:
                park_rec[num] = mins
        else:
            park_min[num] += mins-park_rec[num]
            park_rec[num] = -1
        
    
    for key in park_rec.keys():
        if park_rec[key] >= 0:
            park_min[key] += change_min('23:59')-park_rec[key]
            park_rec[key] = 0
    
    answer = cal_fee(fees, park_min)
    
    return answer