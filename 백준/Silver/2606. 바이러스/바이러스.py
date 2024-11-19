n = int(input())
m = int(input())
cnt = 0
arr = [[] for _ in range(n+1)]

for _ in range(m):
	a, b = map(int, input().split())
	arr[a].append(b)
	arr[b].append(a)

def dfs(v):
	global n, arr, check, cnt
	for i in arr[v]:
		if not check[i]:
			check[i] = True
			cnt += 1
			dfs(i)

check = [False] * (n+1)
check[1] = True
dfs(1)
print(cnt)