def solution(arr):
    answer = [0, 0]
    
    def quad_compress(x, y, compress_size):
        representative_value = arr[x][y]
        
        for i in range(x, x + compress_size):
            for j in range(y, y + compress_size):
                if arr[i][j] != representative_value:
                    half_size = compress_size // 2
                    quad_compress(x, y, half_size)
                    quad_compress(x + half_size, y, half_size)
                    quad_compress(x, y + half_size, half_size)
                    quad_compress(x + half_size, y + half_size, half_size)
                    return
        nonlocal answer
        if representative_value in {0, 1}:
            answer[representative_value] += 1
            
    quad_compress(0, 0, len(arr))
    return answer


"""
S내부를 탐색하며, S내부가 동일한 수로 구성되어 있는지 판별
 -동일한 수로 구성되어있을 경우, 해당 initial수 1만큼 count
 -동일하지 않을 경우, 4등분 후 각각에 대해 탐색
"""