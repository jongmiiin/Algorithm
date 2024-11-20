from collections import deque

n, m = map(int, input().split())

miro = [list(map(int, input())) for _ in range(n)]

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
check = [[False]*m for _ in range(n)]
check[0][0] = True
ans = 1e9
cnt = 1

def bfs(yy, xx):
	global n, m, miro, dy, dx, check, ans, cnt
	q = deque()
	q.append((yy, xx))
	while q:
		size = len(q)
		while size:
			size-=1
			y, x = q.popleft()
			if y == n-1 and x == m-1:
				print(cnt)
				return
			for i in range(4):
				ny = y+dy[i]
				nx = x+dx[i]
				if (0<=ny<n) and (0<=nx<m) and (not check[ny][nx]) and (miro[ny][nx] == 1):
					check[ny][nx] = True
					q.append((ny, nx))
		cnt+=1

bfs(0,0)