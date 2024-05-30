def solution(dirs):
    walked = set()
    cur_loc = [0, 0]

    for d in dirs:
        if d == 'U':
            if(checkInvalidation(cur_loc[0], cur_loc[1] + 1)):
                continue
            walk = (cur_loc[0], cur_loc[1], cur_loc[0], cur_loc[1] + 1)
            walked.add(walk)
            cur_loc[1] += 1
        elif d == 'D':
            if(checkInvalidation(cur_loc[0], cur_loc[1] - 1)):
                continue
            walk = (cur_loc[0], cur_loc[1] - 1, cur_loc[0], cur_loc[1])
            walked.add(walk)
            cur_loc[1] -= 1
        elif d == 'R':
            if(checkInvalidation(cur_loc[0] + 1, cur_loc[1])):
                continue
            walk = (cur_loc[0], cur_loc[1], cur_loc[0] + 1, cur_loc[1])
            walked.add(walk)
            cur_loc[0] += 1
        else:
            if(checkInvalidation(cur_loc[0] - 1, cur_loc[1])):
                continue
            walk = (cur_loc[0] - 1, cur_loc[1], cur_loc[0], cur_loc[1])
            walked.add(walk)
            cur_loc[0] -= 1

    return len(walked)
def checkInvalidation(x, y):
    return x < -5 or x > 5 or y > 5 or y < -5
