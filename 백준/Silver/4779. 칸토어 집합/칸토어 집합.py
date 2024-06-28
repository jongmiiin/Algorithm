def f(n):
	if n==0:
		return "-"
	return f(n-1)+(" "*(3**(n-1)))+f(n-1)

while True:
	try:
		n = int(input())
		print(f(n))
	except:
		break