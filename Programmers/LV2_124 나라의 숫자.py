def solution(n):
    convert = ['4', '1', '2']
    answer = ''
    
    while n > 0:
        remainder = n % 3
        answer = convert[remainder] + answer
        if remainder == 0:
            n = n // 3 - 1
        else:
            n = n // 3
        
    return answer