from collections import deque

n, k = map(int, input().split())

dx = [-1, 1]
cnt = 0
check = [False] * 100001

def bfs(n, k):
	global dx, cnt, check
	q = deque()
	q.append(n)
	while q:
		size = len(q)
		while size:
			size-=1
			x = q.popleft()
			if x == k:
				print(cnt)
				return
			for i in range(3):
				if i == 2:
					nx = 2*x
				else:
					nx = x+dx[i]
				if 0<=nx<=100000 and not check[nx]:
					q.append(nx)
					check[nx] = True
		cnt+=1
bfs(n, k)