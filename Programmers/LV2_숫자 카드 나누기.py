from functools import reduce
import math

def solution(arrayA, arrayB):
    gcdA = get_gcd_from_list(arrayA)
    gcdB = get_gcd_from_list(arrayB)
    
    case1 = gcdA if can_not_divide_all(arrayB, gcdA) else 0
    case2 = gcdB if can_not_divide_all(arrayA, gcdB) else 0
    
    answer = max(case1, case2)
    return answer
        
def get_gcd_from_list(arr):
    return reduce(math.gcd, arr)

def can_not_divide_all(arr, n):
    return all(e % n != 0 for e in arr)
    