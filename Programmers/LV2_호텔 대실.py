def solution(book_time):
    """
    최소 객실만을 이용해 예약 손님들을 처리하고 싶음
    사용된 객실은 최소 10분간은 청소를 해야 다음 손님들이 이용가능
    필요한 최소 객실 수는?
    """
    
    # booking을 어떻게 구현을 해야할까?
    # 1. sorting이후에 이중 포문?
    book_time.sort()
    print(book_time)
    room_state = []
    
    for customer in book_time:
        check_in, check_out = customer
        flag = True
        # 현재 사용 중인 룸을 보고, 이미 체크아웃한 룸이 있다면, 10분을 더해봤을 때 현재 고객의 체크인 시간과 비교
        for i, room_out_time in enumerate(room_state):
            if is_room_available(room_out_time, check_in):
                print("aaa")
                room_state[i] = check_out
                flag = False
                break
        
        # 만약 기존 룸이 없다면, 그냥 room추가
        if flag:
            room_state.append(check_out)
    
    answer = len(room_state)
    return answer

def is_room_available(room_check_out, customer_check_in):
    o_h, o_m = map(int, room_check_out.split(':'))
    i_h, i_m = map(int, customer_check_in.split(':'))
    
    o_h = o_h + ((o_m + 10) // 60)
    o_m = (o_m + 10) % 60
    
    return i_h > o_h or (i_h == o_h and i_m >= o_m)
    