s = input()
arr = []
ans = 0

def f(lev):
	global s, arr, ans, alps, alps_cnt
	if lev == len(s):
		ans += 1
		return
	for alp in alps:
		if alps_cnt[alp] == 0:
			continue
		if not arr or arr[-1] != alp:
			alps_cnt[alp] -= 1
			arr.append(alp)
			f(lev+1)
			alps_cnt[alp] += 1
			arr.pop()

alps = set()
alps_cnt = dict()

for c in s:
	alps.add(c)
	if c not in alps_cnt:
		alps_cnt[c] = 0
	alps_cnt[c] += 1

f(0)
print(ans)