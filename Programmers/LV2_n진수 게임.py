def solution(n, t, m, p):
    tube = []
    cur_num = 0
    cur_order = 1
    while(len(tube) < t):
        cur_str = convertToNBase(cur_num, n)
        for c in cur_str:
            if cur_order == p:
                tube.append(c)
                if (len(tube) >= t):
                    break
            cur_order += 1
            cur_order = m if cur_order % m == 0 else cur_order % m 
        cur_num += 1
        
    answer = "".join(tube)
    return answer

def convertToNBase(number, N):
    num_dict = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    rev_base = ''
    if(number == 0):
        return '0' 

    while number > 0:
        number, mod = divmod(number, N)
        if(mod >= 10):
            mod = num_dict[mod]
        rev_base += str(mod)

    return rev_base[::-1]

solution(2,4,2,1)