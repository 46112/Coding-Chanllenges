"""
전송 효율을 높이기 위해 카톡 메시지 압축 필요
완벽하게 메시지 복원이 가능한 무손실 압축 알고리즘을 구현해야함
LZW 알고리즘을 통한 구현 채택

<LZW>
1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
5. 단계 2로 돌아간다.
    
"""

def solution(msg):
    answer = []
    
    # LZW압축 사전 초기화
    LZW = {}
    for idx in range(26):
        cur_idx = ord('A') + idx
        dict_key = chr(cur_idx)
        dict_value = idx + 1
        LZW[dict_key] = dict_value
    
    while(msg != ""):
        # 현재 입력과 일치하는 가장 긴 문자열 w 찾기
        search_fail_idx = 1
        while(msg[:search_fail_idx] in LZW):
            if(search_fail_idx == len(msg) + 1):
                break
            search_fail_idx += 1

        # w 색인 번호 출력, 입력에서 w 제거
        w_finish_index = search_fail_idx - 1
        w = msg if search_fail_idx == len(msg) + 1 else msg[:w_finish_index]
        answer.append(LZW[w])
        msg = "" if search_fail_idx == len(msg) + 1 else msg[w_finish_index:]

        # c가 남아있으면 w+c를 사전에 등록
        if(msg != ""):
            new_word = w + msg[0]
            new_word_idx = len(LZW) + 1
            LZW[new_word] = new_word_idx
            
    return answer