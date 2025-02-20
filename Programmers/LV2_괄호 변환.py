def solution(p):
    # 1
    if not p:
        return p
    
    # 2
    u, v = split_balanced_str(p)
    
    # 3
    answer = u + solution(v) if is_correct(u) else '(' + solution(v) + ')' + remove_and_reverse(u)
    return answer

def split_balanced_str(s):
    cnt = 0
    index = 0
    for i, c in enumerate(s):
        cnt += 1 if c == '(' else -1
        if cnt == 0:
            index = i
            break
    return s[:index+1], s[index+1:]

def is_correct(s):
    cnt = 0
    for c in s:
        cnt += 1 if c == '(' else -1
        if cnt < 0:
            return False
    
    return cnt == 0

def remove_and_reverse(s):
    s = s[1:-1]
    return ''.join(')' if c == '(' else '(' for c in s)