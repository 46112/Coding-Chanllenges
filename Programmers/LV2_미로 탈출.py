from collections import deque

def solution(maps):
    is_empty = [[element in "SELO" for element in row] for row in maps]
    start_loc, exit_loc, lever_loc = None, None, None
    
    for i, row in enumerate(maps):
        for j, element in enumerate(row):
            if element in "OX":
                continue
            elif element == "S":
                start_loc = (i, j)
            elif element == "E":
                exit_loc = (i, j)
            elif element == "L":
                lever_loc = (i, j)
                
    # S부터 L까지 이동 + L에서 E까지 이동
    to_lever = bfs(is_empty, start_loc, lever_loc)
    to_exit = bfs(is_empty, lever_loc, exit_loc)
    
    if to_lever <= -1 or to_exit <= -1:
        return -1
    
    return to_lever + to_exit

def bfs(maps, start, end):
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    start_r, start_c = start
    queue = deque([(start_r, start_c, 0)])
    isVisited = [[False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    
    while queue:
        cur_r, cur_c, cnt = queue.popleft()
        
        if (cur_r, cur_c) == end:
            return cnt
        
        for r, c in directions:
            new_r, new_c = cur_r + r, cur_c + c
            if 0 <= new_r < len(maps) and 0 <= new_c < len(maps[0]) and maps[new_r][new_c] and not isVisited[new_r][new_c]:
                queue.append((new_r, new_c, cnt + 1))
                isVisited[new_r][new_c] = True
                
    return -1