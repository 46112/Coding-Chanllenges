def solution(s):
    str_to_list = list(map(int, s.split()))
    return str(min(str_to_list)) + " " + str(max(str_to_list))



s1 = "1 2 3 4"
s2 = "-1 -2 -3 -4"
s3 = "-1 -1"

a1 = "1 4"
a2 = "-4 -1"
a3 = "-1 -1"

print("테스트 통과" if solution(s1)==a1 else "실패")
print("테스트 통과" if solution(s2)==a2 else "실패")
print("테스트 통과" if solution(s3)==a3 else "실패")