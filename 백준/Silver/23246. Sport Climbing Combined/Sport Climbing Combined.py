n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]

def comp(x):
	return (x[1]*x[2]*x[3]),(x[1]+x[2]+x[3]),(x[0])

arr = sorted(arr, key=comp)

for i in range(3):
	print(arr[i][0], end=" ")