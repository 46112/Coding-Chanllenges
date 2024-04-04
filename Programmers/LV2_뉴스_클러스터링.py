from collections import Counter

def solution(str1, str2):
    cluster1 = []
    cluster2 = []
    
    # abcde -> ab, bc, cd, de
    for i in range(len(str1)-1):
        if (not str1[i].isalpha() or not str1[i+1].isalpha()):
            continue
        temp = str1[i:i+2].lower()
        cluster1.append(temp)
    for i in range(len(str2)-1):
        if (not str2[i].isalpha() or not str2[i+1].isalpha()):
            continue
        temp = str2[i:i+2].lower()
        cluster2.append(temp)
    
    if len(cluster1) == 0 and len(cluster2) == 0:
        return 65536
    
    intersection_size = find_intersection_size(cluster1, cluster2)
    union_size = find_union_size(cluster1, cluster2)
    
    jaccard_similarity = intersection_size / union_size
    answer = int(jaccard_similarity * 65536)
    print(answer)
    return answer

def find_intersection_size(cluster1, cluster2):
    cluster1_counter = Counter(cluster1)
    cluster2_counter = Counter(cluster2)

    intersection_counter = cluster1_counter & cluster2_counter
    intersection_size = intersection_counter.total()
    return intersection_size

def find_union_size(cluster1, cluster2):
    cluster1_counter = Counter(cluster1)
    cluster2_counter = Counter(cluster2)

    union_counter = cluster1_counter | cluster2_counter
    union_size = union_counter.total()
    return union_size
    
solution("FRANCE", "french")
solution("handshake", "shake hands")