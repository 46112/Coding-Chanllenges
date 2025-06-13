# 직선이라고 했을 때
# dp[idx] = idx까지 존재할 때 훔칠수 있는 최대 돈
# dp[i] = max(dp[i-1], dp[i-2] + money[i])
# 원형은 시작지점과 끝이 연결되어있음 -> 두가지 케이스 고려(시작을 털기 or 털지 않기)

def solution(money):
    def rob(arr):
        n = len(arr)
        dp = [0 for _ in range(n)]
        dp[0] = arr[0]
        dp[1] = max(arr[0], arr[1])
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2] + arr[i])
        return dp[-1]
    
    answer = max( rob(money[:-1]), rob(money[1:]) )
    return answer