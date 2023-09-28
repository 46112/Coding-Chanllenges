def solution(s):
    word_list = s.split(" ")
    answer = []

    for word in word_list:
        # 단어가 비어있지 않은 경우만 변환 진행
        if word:
            if word[0].isalpha():
                word = word[0].upper() + word[1:].lower()
            else:
                word = word.lower()
            answer.append(word)
        else:
            answer.append("")

    return " ".join(answer)