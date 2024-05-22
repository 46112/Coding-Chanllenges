def solution(prices):
    answer = [0] * len(prices)
    last_time = len(prices) - 1
    stack = []
    
    for cur_time, cur_price in enumerate(prices):
        while stack and stack[-1][1] > cur_price:
            past_time, _ = stack.pop() # 해당 시점의 가격은 현재 시점에서 떨어진다
            answer[past_time] = cur_time - past_time
        stack.append((cur_time, cur_price))

    for time, _ in stack:#stack에는 끝까지 하락하지 않은 가격들만 남아있다
        answer[time] = last_time - time
    
    return answer