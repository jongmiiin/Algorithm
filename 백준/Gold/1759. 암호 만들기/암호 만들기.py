vowels = ['a', 'e', 'i', 'o', 'u']
ans = []

def f(idx, lev):
	global l, c, ans, vowels, arr
	if lev == l:
		cnt = 0
		for char in ans:
			if char in vowels:
				cnt+=1
		if 0<cnt<l-1:
			print("".join(ans))
	else:
		for i in range(idx, c):
			ans.append(arr[i])
			f(i+1, lev+1)
			ans.pop()


l, c = map(int, input().split())
arr = input().split()
arr.sort()
f(0, 0)