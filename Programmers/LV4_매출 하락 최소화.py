"""
dp[node][1] = node 직원이 참석했을 때, 매출 손실
= sales[node] + 시그마 min { dp[child][0], dp[child][1] } = node번 직원의 하루 매출액 + 자식들의 참석 여부에 따른 매출 손실액 중 최소일 경우만 선택해 시그마 연산

dp[node][0] = node 직원이 참석안했을 때, 매출 손실
= 시그마 min { dp[child][0], dp[child][1] } // 단, 최소 하나의 자식은 참석해야 함
"""

def solution(sales, links):
    EMPLOYEE_NUM = len(sales)
    
    # link 정보를 이용해 팀장과 팀원 정보 graph 작성
    # 1 ~ N번이 아닌 0 ~ N-1번으로 지정
    graph = [[] for _ in range(EMPLOYEE_NUM)]
    for chief, worker in links:
        graph[chief-1].append(worker-1)
    
    # dp[node][0] = node 직원이 워크숍에 불참할 때, node 서브트리(팀 전체)에서 만족하는 최소비용
    # dp[node][1] = node 직원이 워크숍에 참석할 때, node 서브트리(팀 전체)에서 만족하는 최소비용
    dp = [[0, 0] for _ in range(EMPLOYEE_NUM)]
    isVisited = [False] * EMPLOYEE_NUM
    
    # dfs
    def dfs(node):
        isVisited[node] = True
        
        # 초기값 설정
        dp[node][0] = 0
        dp[node][1] = sales[node]
        
        # 후위 연산을 통해 자식들에 대한 dp값을 먼저 구함
        for child in graph[node]:
            if not isVisited[child]:
                dfs(child)
            
            dp[node][1] += min(dp[child][0], dp[child][1])
        
        # 팀장이 참석을 안 할 경우에는 팀원들 중 하나는 반드시 참석을 해야함
        isChildAttended = False
        min_diff = float('inf')
        
        for child in graph[node]:
            child_absence = dp[child][0]
            child_attend = dp[child][1]
            if child_absence < child_attend:
                dp[node][0] += child_absence
                min_diff = min(min_diff, child_attend - child_absence)
            else:
                dp[node][0] += child_attend
                isChildAttended = True
        
        if (graph[node] and not isChildAttended):
            dp[node][0] += min_diff
    
    # 맨 위(CEO)부터 트리를 dfs탐색한다
    dfs(0)
        
    return min(dp[0][0], dp[0][1])