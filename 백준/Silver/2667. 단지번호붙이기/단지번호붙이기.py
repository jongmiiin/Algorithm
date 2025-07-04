n = int(input())

arr = [input() for _ in range(n)]
check = [[False] * n for _ in range(n)]

area_cnt = 0
cnt_list = []
tmp_cnt = 0

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

def dfs(y, x):
	global arr, check, tmp_cnt
	check[y][x] = True
	tmp_cnt+=1
	for i in range(4):
		ny = y+dy[i]
		nx = x+dx[i]
		if ny<0 or ny>=n or nx<0 or nx>=n or check[ny][nx]==True or arr[ny][nx]=='0':
			continue
		dfs(ny, nx)

for i in range(n):
	for j in range(n):
		if arr[i][j]=='1' and check[i][j]==False:
			area_cnt+=1
			dfs(i, j)
			cnt_list.append(tmp_cnt)
			tmp_cnt = 0

print(area_cnt)
cnt_list = sorted(cnt_list)
for cnt in cnt_list:
	print(cnt)