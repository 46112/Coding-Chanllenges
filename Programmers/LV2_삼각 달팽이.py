def solution(n):
    array = [[0]*n for _ in range(n)]
    direction = [(1,0), (0,1), (-1,-1)]
    dir_idx = 0
    x, y = 0, 0
    cur_num = 1
    
    # 아래 방향 => x++, 오른쪽 방향 => y++, 왼위 => x-- y--
    while True:
        array[x][y] = cur_num
        cur_num += 1
        
        # 더 이상 갈 곳이 없을 때까지
        dx, dy = direction[dir_idx]
        if (x + dx == n or y + dy == n or array[x+dx][y+dy] != 0):
            dir_idx = (dir_idx + 1) % 3
            dx, dy = direction[dir_idx]
            if (x + dx == n or y + dy == n or array[x+dx][y+dy] != 0):
                break
        x += dx
        y += dy
    
    answer = []
    for one_dimention_arr in array:
        for number in one_dimention_arr:
            if number == 0:
                break
            answer.append(number)
    
    return answer