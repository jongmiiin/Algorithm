n, c = map(int, input().split())

houses = [int(input()) for _ in range(n)]
houses = sorted(houses)

l = 0
r = max(houses)

def is_possible(dis):
	global houses, n, c
	cnt = 1
	ex_house = houses[0]
	for i in range(1, n):
		if houses[i]-ex_house>=dis:
			cnt+=1
			ex_house = houses[i]
	return (cnt>=c)


while l<=r:
	mid = (l+r)//2
	if is_possible(mid):
		l = mid+1
		ans = mid
	else:
		r = mid-1

print(ans)