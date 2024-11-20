import sys
sys.setrecursionlimit(10**9)
n = int(input())

areas = [list(map(int, input().split())) for _ in range(n)]

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

def dfs(y, x, h):
	global n, areas, dy, dx, check
	for i in range(4):
		nx = x+dx[i]
		ny = y+dy[i]
		if 0<=nx<n and 0<=ny<n and not check[ny][nx] and areas[ny][nx]>=h:
			check[ny][nx] = True
			dfs(ny, nx, h)

ans = 1

for k in range(101):
	check = [[False]*(n+1) for _ in range(n+1)]
	cnt = 0
	for i in range(n):
		for j in range(n):
			if areas[i][j]>=k and not check[i][j]:
				check[i][j] = True
				cnt+=1
				dfs(i, j, k)
	ans = max(ans, cnt)
	
print(ans)