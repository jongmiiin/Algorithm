def solution(enroll, referral, seller, amount):
    answer = [0] * int(len(enroll))
    boss = dict()
    enroll_index = dict()
    
    for i in range(len(enroll)):
        boss[enroll[i]] = referral[i]
        enroll_index[enroll[i]] = i
    
    def f(seller, money):
        rest_money = money - int(money*0.1)
        answer[enroll_index[seller]] += rest_money
        
        if boss[seller] != '-' and int(money*0.1) >= 1:
            f(boss[seller], int(money*0.1))
        else:
            return
    
    for i in range(len(seller)):
        f(seller[i], amount[i]*100)
        
    return answer

    
        