import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    if(scoville[0] >= K):
        return 0
    
    mix_cnt = 0
    while(len(scoville) >= 2):
        f = heapq.heappop(scoville)
        s = heapq.heappop(scoville)
        
        new = f + (s * 2)
        mix_cnt += 1
        heapq.heappush(scoville, new)
        if(scoville[0] >= K):
            return mix_cnt
        
    return -1