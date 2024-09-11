import itertools

def solution(orders, course):
    """
    단품 메뉴 조합 -> 코스요리
    가장 많이 함께 주문이 들어온 메뉴들을 조합
    코스요리는 최소 2가지 이상의 단품메뉴로 구성
    코스요리에 넣을 단품은 최소 2명 이상의 손님들로부터 주문이 되었어야 함
    
    return 할 때는 오름차순 정렬
    """
    # 1. 26개의 알파벳을 i개로 조합? 26 Comb i
    # 2. orders이용해 count ('A' in order and 'B' in order)
    # 3. count max인 조합들 result에 추가
    
    answer = []
    for r in course:
        counter = {}
        for order in orders:
            nCr = itertools.combinations(order, r)
            for k in list(nCr):
                fix_key = ''.join(sorted(k))
                counter[fix_key] = counter.get(fix_key, 0) + 1
        max_orders = max(counter.values()) if bool(counter) else 0
        if max_orders == 1:
            continue
        answer.extend([k for k,v in counter.items() if v == max_orders])
    
    return sorted(answer)