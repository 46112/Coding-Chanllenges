def solution(phone_book):
    phone_dict = {}
    for phone_number in phone_book:
        phone_dict[phone_number] = 1
    
    for phone_number in phone_book:
        buffer = ""
        for c in phone_number:
            buffer += c
            if buffer in phone_dict and buffer != phone_number:
                return False
    return True

case1 = ["119", "97674223", "1195524421"]
case2 = ["123","456","789"]
case3 = ["12","123","1235","567","88"]

print(solution(case1))
print(solution(case2))
print(solution(case3))