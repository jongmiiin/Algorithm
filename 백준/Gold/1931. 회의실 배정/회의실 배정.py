n = int(input())

meeting = []

for _ in range(n):
	a, b = map(int, input().split())
	meeting.append((a, b))

meeting = sorted(meeting, key=lambda x: (x[1], x[0]))

cnt = 0
ended_time = 0

for time in meeting:
	if time[0]>=ended_time:
		cnt+=1
		ended_time = time[1]

print(cnt)