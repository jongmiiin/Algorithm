n = int(input())

arr = [0 for _ in range(n+1)]

if n == 1:
	print(0)
elif n<4:
	print(1)
else:
	arr[2] = 1
	arr[3] = 1

	for i in range(4,n+1):
		tmp = [arr[i-1]]

		if i%2 == 0:
			tmp.append(arr[i//2])

		if i%3 == 0:
			tmp.append(arr[i//3])

		arr[i] = min(tmp) + 1

	print(arr[n])