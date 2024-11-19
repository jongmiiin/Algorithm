from collections import deque

n, m, v = map(int, input().split())

arr = [[] for _ in range(n+1)]

for _ in range(m):
	a, b = map(int, input().split())
	arr[a].append(b)
	arr[b].append(a)

for i in range(1, n+1):
	arr[i].sort()

def dfs(v):
	global arr, check
	if check[v]:
		return
	check[v] = True
	print(v, end=" ")
	for i in arr[v]:
		dfs(i)

def bfs(vv):
	global arr, check
	q = deque()
	q.append(vv)
	check[vv] = True
	while q:
		now = q.popleft()
		print(now, end=" ")
		for i in arr[now]:
			if check[i]:
				continue
			q.append(i)
			check[i] = True

check = [False] * (n+1)
dfs(v)
print()

check = [False] * (n+1)
bfs(v)