class User:
    def __init__(self, user_id, nickname, is_in=False):
        self.user_id = user_id
        self.nickname = nickname
        self.is_in = is_in
    
    def change_nickname(self, nickname):
        self.nickname = nickname
    
    def enter_chat_room(self, nickname):
        self.change_nickname(nickname)
        self.is_in = True
        
    def leave_chat_room(self):
        self.is_in = False
    
    def get_msg_from_log(self, log_type):
        if log_type == "Enter":
            return f"{self.nickname}님이 들어왔습니다."
        elif log_type == "Leave":
            return f"{self.nickname}님이 나갔습니다."
        else:
            return "Not printable log"
        
def solution(record):
    user_dict = {}
    logs = []
    
    for record_str in record:
        tokens = record_str.split()
        log_type, user_id, *args = tokens
        
        if log_type not in {"Enter", "Leave", "Change"}:
            raise ValueError(f"Invalid log_type {log_type}")
        
        if log_type == "Enter":
            nickname = args[0]
            if user_id not in user_dict:
                user_dict[user_id] = User(user_id, nickname)
            user_dict[user_id].enter_chat_room(nickname)
            logs.append(("Enter", user_id))
        elif log_type == "Leave":
            user_dict[user_id].leave_chat_room()
            logs.append(("Leave", user_id))
        elif log_type == "Change":
            nickname = args[0]
            user_dict[user_id].change_nickname(nickname)
    
    return [user_dict[user_id].get_msg_from_log(log_type) for log_type, user_id in logs]