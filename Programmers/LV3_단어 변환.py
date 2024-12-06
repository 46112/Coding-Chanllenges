from collections import deque

def solution(begin, target, words):
    """
    목표: begin을 target으로 변환하려면 최소 몇 단계 소요되는가?
    - 한 번에 하나의 알파벳만 변환
    - 변환될 때 단어는 words안에 존재해야 함
    """
    # 만약 target이 words에 존재하지 않을 경우 즉시 return 0
    if target not in words:
        return 0
    
    """
    무조건 words안의 단어로 분기되어야 함
    이미 사용된 words로 분기되어서는 안 됨 -> 결국에는 동일한 케이스이므로
    -> 한 번 방문된 words는 다시 방문해서는 안 됨
    """
    # BFS로 찾기
    return bfs(begin, target, words)
    
def bfs(begin_word, goal, words):
    q = deque()
    q.append([begin_word, 0])
    # isVisited = [False for _ in range(len(words))]
    while(q):
        cur_word, cur_step = q.popleft()
        if cur_word == goal:
            return cur_step
        if cur_step > len(words):
            return 0
        
        for candidate in words:
            if isPossible(cur_word, candidate):
                q.append([candidate, cur_step + 1])
    
    return 0
    
CONVERT_CONDITION = 1
# 단어 변환이 가능한 가 확인 해주는 함수
def isPossible(before, after):
    count = 0
    for before_char, after_char in zip(before, after):
        if not before_char == after_char:
            count += CONVERT_CONDITION
        if count > CONVERT_CONDITION:
            return False
    return True