from math import sqrt

def k_ary(n, k):
    ret = ''
    while n > 0:
        ret+=str(n%k)
        n = n//k
        
    return ret[::-1]

def is_prime(x):
    if x < 2:
        return False

    for i in range(2, int(sqrt(x)) + 1):
        if x % i == 0:
            return False

    return True

def solution(n, k):
    answer = 0
    k_num = k_ary(n, k)
    k_list = k_num.split('0')
    
    for kk in k_list:
        if kk == '':
            continue
        if is_prime(int(kk)):
            answer+=1
            
    return answer