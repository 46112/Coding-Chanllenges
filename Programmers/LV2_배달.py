import heapq

def solution(N, road, K):
    inf = float('inf')
    graph = [[inf] * (N+1) for _ in range(N+1)]
    
    for a,b,c in road:
        if graph[a][b] > c:
            graph[a][b] = c
            graph[b][a] = c
    
    isVisited = [False] * (N+1)
    min_dist = [inf] * (N+1)
    min_dist[1] = 0
    next_visit = [(1,0)]
    
    while next_visit:
        cur_node, cur_dist = heapq.heappop(next_visit)
        
        if cur_dist > min_dist[cur_node]:
            continue
        
        for i in range(1, N+1):
            if graph[cur_node][i] != inf:
                new_dist = cur_dist + graph[cur_node][i]
                if new_dist < min_dist[i]:
                    min_dist[i] = new_dist
                    heapq.heappush(next_visit, (i, new_dist))
    
    return sum(1 for d in min_dist if d <= K)