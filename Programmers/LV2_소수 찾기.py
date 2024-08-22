from itertools import permutations

def solution(numbers):
    # 목표: 한자리 숫자들을 이어붙여 소수를 몇개 만들 수 있을지 구하기
    
    # set 선언
    prime_num_set = set()
    
    # list<string> 선언
    num_papers = []
    for n in numbers:
        num_papers.append(str(n))
    
    # 1,2, ... len(num_papers) 만큼 permutation 순열 조합
    for r in range(1, len(num_papers) + 1):
        pmt = permutations(num_papers, r)
        number_comb = set([''.join(tups) for tups in pmt])
        for n in number_comb:
            number = int(n)
            if isPrime(number):
                prime_num_set.add(number)
            
    print(prime_num_set)
    answer = len(prime_num_set)
    return answer

def isPrime(n):
    if n < 2:
        return False
    
    for d in range(2, n//2 + 1):
        if (n % d == 0):
            return False
    return True