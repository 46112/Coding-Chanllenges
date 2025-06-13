# dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1])
# 해당 지점까지 이동하는데 최대값 = 해당 지점 값 + 아래 두개 중 더 큰 값

def solution(triangle):
    height = len(triangle)
    dp = [row[:] for row in triangle]
    
    for i in range(height-2, -1, -1):
        for j in range(len(triangle[i])):
            dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1])
            
    return dp[0][0]