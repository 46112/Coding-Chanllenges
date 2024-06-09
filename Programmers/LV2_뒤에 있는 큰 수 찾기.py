def solution(numbers):
    answer = []
    stack = []
    
    answer.append(-1)
    stack.append(numbers[-1])
    numbers.pop()
    
    for num in reversed(numbers):
        while(stack and num >= stack[-1]):
            stack.pop()
        if(stack):
            answer.append(stack[-1])
        else:
            answer.append(-1)
        stack.append(num)
            
    return list(reversed(answer))