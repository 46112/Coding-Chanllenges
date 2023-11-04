def solution(s):
    stack = []
    
    for char in s:
        if char == "(":
            stack.append(char)
        else:
            try:
                stack.pop()
            except:
                return False
            
    
    return not stack