def rec(inx, lev):
	global arr, ans, n
	if lev==6:
		for i in ans:
			print(i, end=" ")
		print()
		return
	for i in range(inx, n):
		ans.append(arr[i])
		rec(i+1, lev+1)
		ans.pop()

while True:
	ans = []
	I = list(map(int, input().split()))
	n = I[0]
	arr = I[1:]
	if n==0:
		break
	rec(0, 0)
	print()