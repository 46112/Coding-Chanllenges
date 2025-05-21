from heapq import heappush, heappop

class DualPriorityQueue:
    def __init__(self):
        self.min_heap = []
        self.max_heap = []
        self.entry_id = 0
        self.deleted = set()
    
    def insert(self, value):
        heappush(self.min_heap, (value, self.entry_id))
        heappush(self.max_heap, (-value, self.entry_id))
        self.entry_id += 1
    
    def _sync(self, heap):
        while heap and heap[0][1] in self.deleted:
            heappop(heap)
    
    def delete_min(self):
        self._sync(self.min_heap)
        if self.min_heap:
            val, id = heappop(self.min_heap)
            self.deleted.add(id)
    
    def delete_max(self):
        self._sync(self.max_heap)
        if self.max_heap:
            val, id = heappop(self.max_heap)
            self.deleted.add(id)
    
    def get_min(self):
        self._sync(self.min_heap)
        return self.min_heap[0][0] if self.min_heap else 0
    
    def get_max(self):
        self._sync(self.max_heap)
        return -self.max_heap[0][0] if self.max_heap else 0

def apply_operation(instruction, num, queue):
    if instruction == 'I':
        queue.insert(num)
    elif instruction == 'D':
        if num == 1:
            queue.delete_max()
        elif num == -1:
            queue.delete_min()
            
def solution(operations):
    queue = DualPriorityQueue()
    for op in operations:
        instruction, num = op.split()
        apply_operation(instruction, int(num), queue)
        
    return [queue.get_max(), queue.get_min()]