s = input()
check = [False] * len(s)
arr = []
cnt = 0

def fac(x):
	if x == 0:
		return 1
	return fac(x-1)*x

def f(lev):
	global s, check, arr, cnt
	if lev == len(s):
		flag = True
		for i in range(len(arr)-1):
			if arr[i]==arr[i+1]:
				flag = False
		if flag:
			cnt+=1
	else:
		for i in range(len(s)):
			if not check[i]:
				check[i] = True
				arr.append(s[i])
				f(lev+1)
				arr.pop()
				check[i] = False
f(0)
for i in range(ord('a'), ord('z')+1):
	cnt//=fac(s.count(chr(i)))
print(cnt)