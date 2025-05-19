from heapq import heappop, heappush, heapify

def solution(jobs):
    indexed_jobs = [(req, dur, idx) for idx, (req, dur) in enumerate(jobs)]
    indexed_jobs.sort()
    
    waiting_queue = []
    request_idx = 0
    completed_cnt = 0
    cur_time = 0
    total_turnaround = 0
    
    while completed_cnt < len(jobs):
        # 작업 도중에 들어왔을 지도 모르는 요청들을 대기 큐에 저장시켜야 한다    
        while request_idx < len(jobs) and indexed_jobs[request_idx][0] <= cur_time:
            req, dur, idx = indexed_jobs[request_idx]
            heappush(waiting_queue, (dur, req, idx))
            request_idx += 1
        
        if waiting_queue:
            dur, req, idx = heappop(waiting_queue)
            cur_time += dur
            completed_cnt += 1
            total_turnaround += (cur_time - req)
        else:
            cur_time = indexed_jobs[request_idx][0]
        
    return total_turnaround // len(jobs)