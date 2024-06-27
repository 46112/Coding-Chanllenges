def solution(skill, skill_trees):
    answer = 0
    for user_tree in skill_trees:
        if (isValid(skill, user_tree)):
            answer += 1
    return answer

def isValid(skill, skill_tree):
    order = {sk:i for i, sk in enumerate(skill_tree)}
    # D: 4, B: 0, C: 3
    # 스킬은 선행스킬을 먼저 배워야 함
    for i, s in enumerate(skill):
        cur = order.get(s)
        if cur is None:
            continue
        else:
            if i == 0:
                continue
            prev = order.get(skill[i-1])
            if (prev is None) or (prev > cur):
                return False
    return True

"""
def solution(skill, skill_trees):
    skill_range = set([s for s in skill])
    
    answer = 0
    for user_tree in skill_trees:
        if (isValid(skill, user_tree, skill_range)):
            answer += 1
    return answer

def isValid(skill, user_tree, skill_range):
    skill_stack = [s for s in skill]
    
    for user_skill in user_tree:
        if user_skill in skill_range:
            if (len(skill_stack) != 0 and user_skill != skill_stack.pop(0)):
                return False
        else:
            pass
    return True
"""