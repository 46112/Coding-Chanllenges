def solution(n, costs):
    costs.sort(key=lambda x:x[2])
    parent = [i for i in range(n)]

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(a, b):
        root_a = find(a)
        root_b = find(b)
        if root_a != root_b:
            parent[root_b] = root_a
            return True
        return False
    
    total_costs = 0
    for i1, i2, cost in costs:
        if union(i1, i2):
            total_costs += cost
        
    return total_costs