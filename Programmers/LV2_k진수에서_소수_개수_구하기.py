import math

def solution(n, k):
    k_num = convertNumber(n, k)
    numbers = [int(e) for e in k_num.split('0') if e != '']
    
    count = 0
    for num in numbers:
        if(isPrime(num)):
            count += 1

    return count

def convertNumber(n, k):
    numbers = []
    while(n != 0):
        rest = n % k
        numbers.append(str(rest))
        n = int(n / k)
    numbers.reverse()
    return ''.join(numbers)

def isPrime(n):
    if n <= 1:
        return False
    
    root_n = int(math.sqrt(n)) + 1
    for i in range(2, root_n):
        if(n % i == 0):
            return False
    
    return True