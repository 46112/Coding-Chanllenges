def solution(a, b, g, s, w, t):
    """
    a: 목표 금 무게
    b: 목표 은 무게
    g: i번 도시가 보유한 금 (리스트)
    s: i번 도시가 보유한 은 (리스트)
    w: i번 도시 트럭의 1회 최대 적재중량 (리스트)
    t: i번 도시 트럭의 편도 이동 시간 (리스트)
    
    return: 최소 시간
    """
    n = len(t) # 도시의 수
    
    # "mid 시간 내에 a 이상 금, b 이상 은을 옮길 수 있는가?" 여부 반환
    def can_deliver_in_time(mid):
        # 도시들이 mid 시간 동안 운반할 수 있는 광물의 양
        total_gold = 0
        total_silver = 0
        total_mineral = 0
        
        for i in range(n):
            count = mid // (t[i] * 2) + (1 if mid % (t[i] * 2) >= t[i] else 0) # 운반 횟수
            availability = w[i] * count
            
            total_gold += min(g[i], availability)
            total_silver += min(s[i], availability)
            total_mineral += min(g[i] + s[i], availability)
        
        return total_gold >= a and total_silver >= b and total_mineral >= a + b
    
    # 이분 탐색 범위 설정
    left = 0
    right = 10**15  # t[i] 최대는 10**5, a+b 최대는 2*10**9, 따라서 대략적인 최대 2*10**14
    answer = right

    while left <= right:
        mid = (left + right) // 2
        if can_deliver_in_time(mid):
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
            
    return answer