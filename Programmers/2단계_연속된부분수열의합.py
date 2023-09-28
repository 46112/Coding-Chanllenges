"""
비내림차순으로 정렬된 수열이 주어질 때, 다음 조건을 만족하는 부분 수열을 찾으려고 합니다.

기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열이어야 합니다.
부분 수열의 합은 k입니다.
합이 k인 부분 수열이 여러 개인 경우 길이가 짧은 수열을 찾습니다.
길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에 나오는 수열을 찾습니다.
수열을 나타내는 정수 배열 sequence와 부분 수열의 합을 나타내는 정수 k가 매개변수로 주어질 때, 위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return 하는 solution 함수를 완성해주세요. 이때 수열의 인덱스는 0부터 시작합니다.
"""

"""
5 ≤ sequence의 길이 ≤ 1,000,000
    1 ≤ sequence의 원소 ≤ 1,000
    sequence는 비내림차순으로 정렬되어 있습니다.
5 ≤ k ≤ 1,000,000,000
    k는 항상 sequence의 부분 수열로 만들 수 있는 값입니다.
"""

"""

sequence	                k	        result

[1, 2, 3, 4, 5]	            7	        [2, 3]
[1, 1, 1, 2, 3, 4, 5]	    5	        [6, 6]
[2, 2, 2, 2, 2]	            6	        [0, 2]

"""

# 합이 k인 수열 중 가장 길이가 짧은 것을 찾아라
# 그 다음 그 짧은 수열들 중에서 가장 앞에 있는 것(시작 인덱스가 작은 것)을 찾아 그 수열의 시작 인덱스와 마지막 인덱스를 찾는다.
def solution(sequence, k):
    # start는 합을 구할 때 맨 첫번째 인덱스, end는 마지막 인덱스
    start, end = 0, 0
    current_sum = sequence[0]
    result = None

    while end < len(sequence):
        # 합이 k보다 작을 경우 end를 한칸 앞으로 옮기고 합을 업데이트
        if current_sum < k:
            end += 1
            if end < len(sequence):
                current_sum += sequence[end]

        # 합이 k보다 클 경우 start 인덱스 값을 빼주어 그 다음부터 시작한 합을 구할 수 있도록 함
        elif current_sum > k:
            current_sum -= sequence[start]
            start += 1

        # 합과 k가 같을 경우
        else:
            # 만약 새로 찾은 case가 기존과 비교하여 길이가 짧거나 기존에 값이 존재하지 않을 때
            # 등호를 넣지 않았기에 자동으로 수열 중에 가장 앞에 있는 것이 선택됨
            if result is None or end - start < result[1] - result[0]:
                result = [start, end]

            # 다시 그 다음부터 찾게 됨
            current_sum -= sequence[start]
            start += 1

    # 찾지 못했을 경우 전체 수열 그대로 return
    if result is None:
        return [0, len(sequence) - 1]
    return result


sequence1 = [1, 2, 3, 4, 5]
sequence2 = [1, 1, 1, 2, 3, 4, 5]
sequence3 = [2, 2, 2, 2, 2]

k1, k2, k3 = 7, 5, 6

result1 = [2, 3]
result2 = [6, 6]
result3 = [0, 2]

print("테스트 통과" if solution(sequence1, k1) == result1 else "테스트 실패")
print("테스트 통과" if solution(sequence2, k2) == result2 else "테스트 실패")
print("테스트 통과" if solution(sequence3, k3) == result3 else "테스트 실패")
