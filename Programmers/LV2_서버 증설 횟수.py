def solution(players, m, k):
    number_of_server_per_hour = {h: 0 for h in range(24)}
    expansion_cnt = 0
    
    for cur_hour, cur_player_num in enumerate(players):
        needed_server = cur_player_num // m
        if number_of_server_per_hour[cur_hour] < needed_server:
            add = needed_server - number_of_server_per_hour[cur_hour]
            increase_values(number_of_server_per_hour, cur_hour, add, k)
            expansion_cnt += add
            
    return expansion_cnt

def increase_values(dictionary, start_key, add, count):
    end_key = min(start_key + count, 24)
    for key in range(start_key, end_key):
        dictionary[key] += add