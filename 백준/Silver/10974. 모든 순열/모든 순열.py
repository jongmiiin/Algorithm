n = int(input())
ans = []
check = [False] * (n+1)

def f(lev):
	global ans, n, check
	if lev == n:
		print(*ans)
	else:
		for i in range(1, n+1):
			if not check[i]:
				check[i] = True
				ans.append(i)
				f(lev+1)
				ans.pop()
				check[i] = False

f(0)