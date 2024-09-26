vows = ['a','e','i','o','u']

def pos():
	global ans
	vow = 0
	cons = 0
	for i in ans:
		if i in vows :
			vow+=1
		else:
			cons+=1
	if vow>=1 and cons>=2:
		return True
	else:
		return False

def rec(idx, lev):
	global arr, ans, n, k
	if lev==n:
		if pos():
			for i in ans:
				print(i, end='')
			print()
		return
	for i in range(idx, k):
		ans.append(arr[i])
		rec(i+1, lev+1)
		ans.pop()

ans = []
n, k = map(int, input().split())
arr = input().split()
arr.sort()
rec(0,0)