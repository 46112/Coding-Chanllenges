# 숫자 N을 num개 사용했을 때 만들 수 있는 숫자 집합 -> dp[num]
# dp[0] = {}, dp[1] = {N}, dp[2] = {NN, N + N, N - N, N * N, N / N}
# dp[3] = {NNN, dp[1]과 dp[2]의 조합, dp[2]와 dp[1]의 조합} ...

def solution(N, number):
    if N == number:
        return 1
    
    dp = [set() for _ in range(9)]

    for i in range(1, 9):
        dp[i].add(int(str(N) * i))

        for j in range(1, i):
            for op1 in dp[j]:
                for op2 in dp[i - j]:
                    dp[i].add(op1 + op2)
                    dp[i].add(op1 - op2)
                    dp[i].add(op1 * op2)
                    if op2 != 0:
                        dp[i].add(op1 // op2)
        
        if number in dp[i]:
            return i

    return -1