from collections import defaultdict

def solution(info, edges):
    # 1. 트리 구성
    graph = defaultdict(list)
    for parent, child in edges:
        graph[parent].append(child)
    
    # 2. DFS 탐색 함수 정의
    def dfs(cur_node, sheep_cnt, wolf_cnt, next_nodes):
        global max_sheep
        if wolf_cnt >= sheep_cnt:
            return
        max_sheep = max(max_sheep, sheep_cnt)
        
        for next_node in next_nodes:
            new_next_nodes = next_nodes.copy()
            new_next_nodes.remove(next_node)
            new_next_nodes.extend(graph[next_node])
            if info[next_node] == 0:
                dfs(next_node, sheep_cnt + 1, wolf_cnt, new_next_nodes)
            else:
                dfs(next_node, sheep_cnt, wolf_cnt + 1, new_next_nodes)
                
    # 3. 초기화 및 탐색 시작
    global max_sheep
    max_sheep = 0
    dfs(0, 1, 0, graph[0])
    
    return max_sheep