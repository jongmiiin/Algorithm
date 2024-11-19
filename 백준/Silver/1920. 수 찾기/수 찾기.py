n = int(input())
a = list(map(int, input().split()))
a.sort()

m = int(input())
nums = list(map(int, input().split()))

def bin(l, r, t):
	while l<=r:
		mid = (l+r)//2
		if a[mid] == t:
			return 1
		elif a[mid]>t:
			r = mid-1
		elif a[mid]<t:
			l = mid+1
	return 0

for num in nums:
	print(bin(0, len(a)-1, num))