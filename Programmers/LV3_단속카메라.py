def solution(routes):
    routes.sort(key=lambda x:x[1])
    
    last_camera = -30001
    camera_cnt = 0
    for start, end in routes:
        if last_camera < start:
            last_camera = end
            camera_cnt += 1
    
    return camera_cnt