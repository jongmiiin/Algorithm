def solution(brown, yellow):
    answer = []
    for i in range(yellow, 0, -1):
        y_x = y_y = 0
        if yellow%i == 0 and i>=(yellow//i):
            y_x = i
            y_y = yellow//i
            if brown == (2*(y_x+2) + 2*(y_y+2) -4) :
                answer.append(y_x+2)
                answer.append(y_y+2)
    return answer