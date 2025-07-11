n, m = map(int, input().split())

trees = list(map(int, input().split()))
trees = sorted(trees)

cur = -1
step = max(trees)

def min_tree(h):
	global trees, m
	diff = 0
	for tree in trees:
		if tree-h > 0:
			diff += tree-h
	if diff >= m:
	 	return True
	else:
	 	return False

while step != 0:
	while (cur+step<max(trees) and min_tree(cur+step) == True):
		cur += step
	step //= 2

print(cur)