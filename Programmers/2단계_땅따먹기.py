COLS = 4

def solution(land):
    N = len(land)
    dp = [land[0][:] for _ in range(2)]

    for i in range(1, N):
        prev_row = dp[(i - 1) % 2]  # 이전 행의 최대 점수를 사용
        current_row = land[i][:]  # 현재 행의 점수를 복사
        
        for cur_col in range(COLS):
            # current_row[cur_col]을 선택한다고 가정했을 때, 최선의 이전 선택
            max_val = max(prev_row[prev_col] for prev_col in range(COLS) if prev_col != cur_col)
            current_row[cur_col] += max_val
        
        dp[i % 2] = current_row

    return max(dp[(N - 1) % 2])

solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]) # 예상값: 16