from math import factorial

def solution(n, k):
    numbers = list(range(1, n+1))
    answer = []
    k -= 1
    
    for i in range(n, 0, -1):
        fact = factorial(i - 1)
        sector_idx = k // fact
        answer.append(numbers.pop(sector_idx))
        k = k % fact
        
    return answer