def solution(n, times):
    left = 0
    right = max(times) * n
    
    answer = 0
    while left <= right:
        mid = (left + right) // 2
        throughput = sum([mid // duration for duration in times])
        
        if throughput >= n:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return answer