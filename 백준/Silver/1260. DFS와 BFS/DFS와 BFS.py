from collections import deque

n, m, v = map(int, input().split())

arr = [[] for _ in range(n+1)]

for _ in range(m):
	a, b = map(int, input().split())
	arr[a].append(b)
	arr[b].append(a)

for i in range(n+1):
	arr[i] = sorted(arr[i])

check = [False] * (n+1)

def dfs(arr, check, v):
	print(v, end=" ")
	check[v] = True
	for i in arr[v]:
		if check[i] == False:
			dfs(arr, check, i)

def bfs(arr, check, v):
	q = deque()
	q.append(v)
	check[v] = True

	while q:
		now = q.popleft()
		print(now, end=" ")
		for i in arr[now]:
			if check[i] == False:
				q.append(i)
				check[i] = True

dfs(arr, check, v)
print()
check = [False] * (n+1)
bfs(arr, check, v)