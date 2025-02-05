import heapq
from collections import defaultdict

"""
S -> K: A와 B가 S에서 K까지 합승해서 이동
K -> A: A는 K에서 A까지 단독 이동
K -> B: B는 K에서 B까지 단독 이동

answer = min(for k in n... dist[s][k] + dist[k][a] + dist[k][b])
"""

def solution(n, s, a, b, fares):
    graph = defaultdict(list)
    for c, d, w in fares:
        graph[c].append((d,w))
        graph[d].append((c,w))
    
    dijkstraS = dijkstra(s, graph, n)
    dijkstraA = dijkstra(a, graph, n)
    dijkstraB = dijkstra(b, graph, n)
    
    candidates = []
    for k in range(1, n+1):
        temp = dijkstraS[k] + dijkstraA[k] + dijkstraB[k]
        candidates.append(temp)
    
    answer = min(candidates)
    return answer

def dijkstra(start, graph, n):
    dist = [float('INF')] * (n+1)
    dist[start] = 0
    heap = [(0,start)]
    while heap:
        cur_weight, cur_node = heapq.heappop(heap)
        if cur_weight > dist[cur_node]:
            continue
        
        for nxt_node, nxt_weight in graph[cur_node]:
            new_weight = cur_weight + nxt_weight
            if dist[nxt_node] > new_weight:
                dist[nxt_node] = new_weight
                heapq.heappush(heap, (new_weight,nxt_node))
    return dist
        