def solution(s, skip, index):
    result = []
    
    # 문자열 s의 각 문자에 대해 규칙을 적용
    for char in s:
        # index만큼 알파벳을 뒤로 이동
        for i in range(index):
            char = chr(((ord(char) - ord('a') + 1) % 26) + ord('a'))
            # skip에 있는 알파벳이면 다시 이동
            while char in skip:
                char = chr(((ord(char) - ord('a') + 1) % 26) + ord('a'))
        result.append(char)
    
    return ''.join(result)

# 예시로 주어진 값을 테스트
s = "aukks"
skip = "wbqd"
index = 5
print(solution(s, skip, index))
