def solution(numbers, target):
    answer = 0
    
    def dfs(idx, sum, is_plus):
        nonlocal answer
        if idx>= len(numbers):
            return
        sum += numbers[idx] if is_plus else numbers[idx]*(-1)
        if idx+1 == len(numbers) and sum == target:
            answer+=1
            return
        dfs(idx+1, sum, True)
        dfs(idx+1, sum, False)
        return
    
    dfs(0, 0, True)
    dfs(0, 0, False)
    return answer
    
    