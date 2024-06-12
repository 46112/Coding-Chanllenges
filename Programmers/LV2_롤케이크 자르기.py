from collections import Counter

def solution(topping):
    chulsu = set()
    brother = Counter(topping)
    answer = 0
    
    for t in topping:
        chulsu.add(t)
        brother[t] -= 1
        if brother[t] == 0:
            brother.pop(t)
        
        if len(chulsu) == len(brother):
            answer += 1
    return answer