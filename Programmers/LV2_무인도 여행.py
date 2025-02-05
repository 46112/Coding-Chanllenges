def solution(maps):
    n = len(maps)
    m = len(maps[0])
    isVisited = [[False] * m for _ in range(n)]
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    def dfs(x, y):
        stack = [(x, y)]
        total = 0
        while(stack):
            cur_x, cur_y = stack.pop()
            if isVisited[cur_x][cur_y]:
                continue
            isVisited[cur_x][cur_y] = True
            total += int(maps[cur_x][cur_y])
            
            for dx, dy in directions:
                tmp_x = cur_x + dx
                tmp_y = cur_y + dy
                if (tmp_x >= 0 and tmp_x < n and tmp_y >= 0 and tmp_y < m) and maps[tmp_x][tmp_y] != 'X' and not isVisited[tmp_x][tmp_y]:
                    stack.append((tmp_x, tmp_y))
        return total
    
    islands = []
    for i in range(n):
        for j in range(m):
            if (not isVisited[i][j]) and maps[i][j] != 'X':
                islands.append(dfs(i, j))
    
    return sorted(islands) if islands else [-1]