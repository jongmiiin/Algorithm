n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]

arr = sorted(arr)

for i in range(n):
	print(*arr[i])