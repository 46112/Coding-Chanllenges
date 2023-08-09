import math

def solution(r1, r2):
    answer = 0
    # x 좌표를 순회하면서 가능한 y 좌표 최대에서 y 좌표 최소를 뺌
    for x in range(1, r2+1):
        y_max = math.floor(math.sqrt(r2**2 - x**2))
        y_min = 0 if x>r1 else math.ceil(math.sqrt(r1**2 - x**2))
        answer += (y_max - y_min + 1)


    return answer * 4