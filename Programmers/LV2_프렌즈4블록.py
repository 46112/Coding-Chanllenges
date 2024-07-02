def solution(m, n, board):# 길이 n 높이 m
    board_info = [list(blocks) for blocks in board]
    removed_block_cnt = 0
    while(True):
        to_be_removed = find_2x2_blocks(board_info)
        if(not to_be_removed):
            break
        
        for i, j in to_be_removed:
            board_info[i][j] = ' '
        
        # 비어있는 칸이 중간에 존재할 경우, 빈칸들은 맨 위로 board_info를 업데이트한다
        for j in range(n):
            empty_row = m - 1
            for i in range(m - 1, -1, -1):
                if board_info[i][j] != ' ':
                    board_info[empty_row][j] = board_info[i][j]
                    if empty_row != i:
                        board_info[i][j] = ' '
                    empty_row -= 1
        removed_block_cnt += len(to_be_removed)
        
    return removed_block_cnt

def find_2x2_blocks(board):
    blocks = set()
    rows = len(board)
    cols = len(board[0])

    for i in range(rows-1):
        for j in range(cols-1):
            if (board[i][j] != ' ' and 
                board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1]):
                blocks.update([(i,j), (i,j+1), (i+1,j), (i+1,j+1)])
    
    return blocks