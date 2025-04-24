from collections import defaultdict

"""
1. 도넛 모양
-> 모든 정점은 1개의 나가는 간선, 1개의 들어오는 간선을 가짐

2. 막대 모양
-> size=1일 때는 0개의 간선
-> 일반적일 경우, 시작점은 1개의 나가는 간선, 0개의 들어오는 간선을 가짐
-> 끝점은 0개의 나가는 간선, 1개의 들어오는 간선을 가짐
-> 나머지 정점들은 1개의 나가는 간선, 1개의 들어오는 간선을 가짐

3. 8자 모양
-> 공유되는 정점은 2개의 나가는 간선, 2개의 들어오는 간선을 가짐
-> 나머지 정점들은 1개의 나가는 간선, 1개의 들어오는 간선을 가짐(도넛 모양이므로)

in: 0 & out >= 2 -> 새로 추가된 정점
in: 0 & out: 0 -> size가 1인 막대 그래프 정점
in: 0 & out: 1 -> 막대 시작점
in: 1 & out: 0 -> 막대 끝점
in: 2 & out: 2 -> 8자 공유점

막대 그래프는 out이 0이 되는 정점을 무조건 하나를 갖는다(in도 마찬가지이지만, size 1인 특이 케이스를 고려)
8자는 공유점 하나(out이 2가 되는 정점)를 무조건 갖는다
"""

def solution(edges):
    # 그래프 구성
    in_degree = defaultdict(int)
    out_degree = defaultdict(int)
    nodes = set()
    for edge in edges:
        start, end = edge
        out_degree[start] += 1
        in_degree[end] += 1
        nodes.update([start, end])
    
    # 생성된 정점 찾기 -> 생성 정점은 out만 존재하고 in이 없음 -> 조건상 그래프는 2개 이상 이므로 out >= 2
    source = -1
    for node in nodes:
        if in_degree[node] == 0 and out_degree[node] >= 2:
            source = node
            break
    
    # 그래프 구분
    donut = bar = eight = 0
    for node in nodes:
        if node == source:
            continue
        if out_degree[node] == 0:
            bar += 1
        elif out_degree[node] == 2:
            eight += 1
    
    donut = out_degree[source] - bar - eight
    return [source, donut, bar, eight]
