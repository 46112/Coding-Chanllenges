from collections import defaultdict, deque

def bfs(start_node, graph, visited):
    q = deque([start_node])
    visited[start_node] = True
    cnt = 1
    
    while q:
        cur_node = q.popleft()
        for neighbor in graph[cur_node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                q.append(neighbor)
                cnt += 1
    return cnt

def solution(n, wires):
    graph = defaultdict(list)
    
    for v1, v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)
    
    answer = float('inf')
    for v1, v2 in wires:
        graph[v1].remove(v2)
        graph[v2].remove(v1)
        
        visited = [False] * (n + 1)
        network1 = bfs(v1, graph, visited)
        network2 = n - network1
        
        answer = min(answer, abs(network1 - network2))
        
        graph[v1].append(v2)
        graph[v2].append(v1)
    
    return answer