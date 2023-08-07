def solution(targets):

    flag = -1
    missaile = 0

    targets.sort()

    for target in targets:
        start, end = target

        # flag 미만까지는 요격 가능함
        if flag > start:
            flag = min(flag, end)
        
        # flag 이상부터는 새로운 미사일을 쏘아야 함
        else:
            missaile += 1
            flag = end

    return missaile

targets = [[4,5],[4,8],[10,14],[11,13],[5,12],[3,7],[1,4]]
print(solution(targets) == 3)