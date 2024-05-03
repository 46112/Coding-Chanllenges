from collections import deque

STARTING_POINT = (0,0)

def solution(maps):
    dx = [1, 0, 0, -1]
    dy = [0, -1, 1, 0]
    
    row_len = len(maps)
    col_len = len(maps[0])    
    
    isVisited = [[False] * col_len for _ in range(row_len)]
    distance = [[-1] * col_len for _ in range(row_len)]
    
    q = deque()
    q.append(STARTING_POINT)
    start_x, start_y = STARTING_POINT
    distance[start_y][start_x] = 1
    isVisited[start_y][start_x] = True

    while(q):
        cur_x, cur_y = q.popleft()
            
        for i in range(4):
            temp_x = cur_x + dx[i]
            temp_y = cur_y + dy[i]
            
            if(checkMapLimit((temp_x, temp_y), (col_len, row_len)) and maps[temp_y][temp_x] == 1):
                if(not isVisited[temp_y][temp_x]):
                    distance[temp_y][temp_x] = distance[cur_y][cur_x] + 1
                    q.append((temp_x, temp_y))
                    isVisited[temp_y][temp_x] = True
    
    return distance[row_len-1][col_len-1]
            
def checkMapLimit(current_location, map_limit):
    x, y = current_location
    x_limit, y_limit = map_limit
    return (0 <= x < x_limit) and (0 <= y < y_limit)