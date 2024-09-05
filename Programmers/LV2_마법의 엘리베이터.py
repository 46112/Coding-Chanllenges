def solution(storey):
    used_magic_stones = 0
    while storey > 0:
        n = storey % 10
        if n > 5:
            used_magic_stones += (10 - n)
            storey += 10
        elif n < 5:
            used_magic_stones += n
        else:# 현재 자릿수가 5이고, 다음 자리가 5이상이면, 10을 더하고 5를 빼는 편이 좋음
            if (storey // 10) % 10 >= 5:
                storey += 10
            used_magic_stones += 5
        storey //= 10
    
    return used_magic_stones