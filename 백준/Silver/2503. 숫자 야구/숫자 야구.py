n = int(input())
infos = [input().split() for _ in range(n)]
ans = 0

for i in range(1,10):
	for j in range(1,10):
		if i == j:
			continue
		for k in range(1,10):
			if i == k or j == k:
				continue
			flag = True
			for num, st, ba in infos:
				st_cnt = (i==int(num[0]))+(j==int(num[1]))+(k==int(num[2]))
				ba_cnt = (i==int(num[1]))+(i==int(num[2]))+(j==int(num[0]))+(j==int(num[2]))+(k==int(num[0]))+(k==int(num[1]))
				if st_cnt != int(st) or ba_cnt != int(ba):
					flag = False
			if flag:
				ans += 1
print(ans)