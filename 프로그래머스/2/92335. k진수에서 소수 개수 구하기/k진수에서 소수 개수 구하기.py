from math import sqrt

def k_ary(n, k):
    ret = ''
    while n > 0:
        ret+=str(n%k)
        n = n//k
    return ret[::-1]

def prime(n):
    flag = [True] * (n+1)
    flag[0] = False
    flag[1] = False
    
    for i in range(2, int(sqrt(n))+1):
        if flag[i]:
            for j in range(i*2, n+1, i):
                flag[j] = False
    return flag

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
    
    # flag = prime(int(k_num))
    
    for kk in k_list:
        if kk == '':
            continue
        if is_prime(int(kk)):
            answer+=1
            
    return answer