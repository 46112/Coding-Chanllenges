def solution(ingredient):
    burger_maker = []
    burger_pattern = [1, 2, 3, 1]
    result = 0
    
    for i in ingredient:
        burger_maker.append(i)
        if burger_maker[-4:] == burger_pattern: # 버거 재료 하나 쌓고 버거 완성되었는지 확인
            result += 1
            for _ in range(4):
                burger_maker.pop()
                
    return result