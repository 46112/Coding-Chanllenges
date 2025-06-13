# m과 n은 100이하 자연수
# 집과 학교 사이의 이동 방법은 우측 이동과 아래 이동밖에 존재하지 않는다 -> 이동을 못하던가 or 가까워지던가 -> 최소 거리 보장
# dp[m][n] = dp[m-1][n](우측 이동) + dp[m][n-1](아래 이동)

DIV = 1000000007

def solution(m, n, puddles):
    puddles = set([(r, c) for c, r in puddles])
    dp = [[0 for j in range(m+1)] for i in range(n+1)]
    dp[1][1] = 1
    
    for r in range(1, n+1):
        for c in range(1, m+1):
            if (r, c) in puddles:
                continue
            dp[r][c] = max(dp[r][c], dp[r-1][c] + dp[r][c-1])
            
    for row in dp:
        print(row)
    return dp[n][m] % DIV