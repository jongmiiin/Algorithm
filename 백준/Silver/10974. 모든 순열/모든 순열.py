n = int(input())

check = [False] * 10
choose = []

def permu(lev):
	if lev == n:
		for i in choose:
			print(i, end=' ')
		print()
		return

	for i in range(1, n+1):
		if check[i] == True:
			continue

		choose.append(i)
		check[i] = True

		permu(lev+1)

		check[i] = False
		choose.pop()

permu(0)