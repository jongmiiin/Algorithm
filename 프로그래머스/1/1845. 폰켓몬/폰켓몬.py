def solution(nums):
    s = set()
    l = len(nums)
    for num in nums:
        s.add(num)
    return len(s) if len(s)<(len(nums)//2) else len(nums)//2