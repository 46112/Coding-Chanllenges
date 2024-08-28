class Bridge:
    def __init__(self, length, limit):
        self.length = length
        self.limit = limit
        self.truck_num = 0
        self.total_weight = 0
        self.info = []
    
    def is_acceptable(self, new_truck):
        return self.truck_num < self.length and (self.total_weight + new_truck) <= self.limit
    
    def get_out(self):
        if self.info:
            tmp, _ = self.info.pop(0)
            self.truck_num -= 1
            self.total_weight -= tmp
    
    def entry(self, new_truck):
        self.info.append(new_truck)
        self.truck_num += 1
        self.total_weight += new_truck[0]

def solution(bridge_length, weight, waiting_line):
    cur_idx = 0
    cur_time = 0
    
    bridge = Bridge(bridge_length, weight)
    
    while cur_idx < len(waiting_line) or bridge.truck_num > 0:
        # 시간 증가
        cur_time += 1
        
        # time이 지났을 때(다 건너갔을 때) brdige내 요소를 어떻게 pop해야할까?
        for _, entry_time in bridge.info:
            if cur_time >= entry_time + bridge_length:
                bridge.get_out()
            else:
                break
        
        # 트럭 수 여유가 있고, 무게 제한이 괜찮음 -> 다리에 올리기
        if cur_idx < len(waiting_line) and bridge.is_acceptable(waiting_line[cur_idx]):
            bridge.entry((waiting_line[cur_idx], cur_time))
            cur_idx += 1
    
    # while문 빠져나왔을 때는 마지막 트럭이 이제 막 건너기 시작했을 때
    return cur_time