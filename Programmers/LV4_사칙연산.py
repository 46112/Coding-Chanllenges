def solution(arr):
    from functools import lru_cache

    @lru_cache(None)
    def compute(start, end):
        if start == end:
            val = int(arr[start])
            return (val, val)
        
        min_val = float('inf')
        max_val = float('-inf')
        
        for i in range(start+1, end, 2):
            op = arr[i]
            left_min, left_max = compute(start, i-1)
            right_min, right_max = compute(i+1, end)
            
            candidates = []
            for l in [left_min, left_max]:
                for r in [right_min, right_max]:
                    if op == '+':
                        candidates.append(l + r)
                    elif op == '-':
                        candidates.append(l - r)
            min_val = min(min_val, *candidates)
            max_val = max(max_val, *candidates)
            
        return (min_val, max_val)
    
    return compute(0, len(arr) - 1)[1]
