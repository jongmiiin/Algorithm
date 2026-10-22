from collections import deque

def solution(begin, target, words):
    answer = 1004
    
    def is_ok(a, b):
        n = len(a)
        cnt = 0
        for i in range(n):
            if a[i] != b[i]:
                cnt += 1
        return True if cnt == 1 else False
    visited = {begin}
    q = deque()
    q.append([begin, 0])
    while q:
        now, cnt = q.popleft()
        if now == target:
            answer = min(answer, cnt)
            continue
        if cnt >= len(words):
            continue
        for word in words:
            if is_ok(now, word) and not word in visited:
                visited.add(word)
                q.append([word, cnt+1])
            
    return answer if answer != 1004 else 0