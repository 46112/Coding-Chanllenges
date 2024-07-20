def solution(numbers):
    answer = []
    for number in numbers:
        # x가 짝수인 경우 x의 가장 낮은 비트가 0이므로, f(x) = x + 1
        if number % 2 == 0:
            answer.append(number + 1)
        else:
            """
            # x가 홀수인 경우
                1. x의 가장 낮은 0비트를 1로 변경
                2. 그 다음 비트를 0으로 변경
            """
            binary_number = '0' + bin(number)[2:]
            zero_index = binary_number.rfind('0')
            binary_number = list(binary_number)
            binary_number[zero_index] = '1'
            binary_number[zero_index + 1] = '0'
            answer.append(int(''.join(binary_number), 2))
    return answer