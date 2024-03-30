"""

실행 대기 큐에서 대기중인 프로세스 하나를 꺼낸다
큐 중에서 우선순위가 더 높은 프로세스가 있으면 방금 꺼낸 프로세스를 다시 큐에 넣는다
없으면 꺼낸 큐를 바로 실행한다 -> 실행 후 종료



"""

case1_priorities = [2, 1, 3, 2]
case1_location = 2

case2_priorities = [1, 1, 9, 1, 1, 1]
case2_location = 0

def solution(priorities, target):
    queue = [(priority, index) for index, priority in enumerate(priorities)]
    execution_order = 0

    while True:
        current = queue.pop(0)

        if has_higher_priority(queue, current[0]):
            queue.append(current)
        else:
            execution_order += 1
            if current[1] == target:
                break

    return execution_order

def has_higher_priority(queue, priority):
    return any(p > priority for p, _ in queue)

answer1 = solution(case1_priorities, case1_location)
answer2 = solution(case2_priorities, case2_location)

print(answer1)
print(answer2)