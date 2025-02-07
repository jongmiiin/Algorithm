def solution(record):
    answer = []
    d = dict()
    for log in record:
        if log[0] != 'L':
            state, user, name = map(str, log.split())
            d[user] = name
                
    for log in record:
        if log[0] == 'E':
            state, user, name = map(str, log.split())
            answer.append(d[user]+'님이 들어왔습니다.')
        elif log[0] == 'L':
            state, user = map(str, log.split())
            answer.append(d[user]+'님이 나갔습니다.')
    return answer