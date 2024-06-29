def solution(order):
    box_order = { num: i+1 for i, num in enumerate(order) }
    
    truck = []
    temp = []
    driver_req = 1
    for box_num in range(1, len(order) + 1):
        if box_order[box_num] == driver_req:
            truck.append(box_num)
            driver_req += 1
        else:
            temp.append(box_num)
        while(temp and box_order[temp[-1]] == driver_req):
            n = temp.pop()
            truck.append(n)
            driver_req += 1
        
    return len(truck)