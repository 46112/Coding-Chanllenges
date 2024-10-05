def solution(m, musicinfos):
    m = replace_sharp(m)
    searched_musics = []
    for musicinfo in musicinfos:
        start_time, end_time, music_name, score = musicinfo.split(',')
        score = replace_sharp(score)
        play_time = calculate_minutes(start_time, end_time)
        real_music = ''
        while play_time > len(score):
            real_music += score
            play_time -= len(score)
        real_music += score[:play_time]
        
        if (m in real_music):
            searched_musics.append((len(real_music), music_name))
    
    if not searched_musics:
        return '(None)'
    
    return max(searched_musics, key=lambda x:x[0])[1]

def calculate_minutes(start, end):
    h1, m1 = map(int, start.split(':'))
    h2, m2 = map(int, end.split(':'))
    s_m = h1 * 60 + m1
    e_m = h2 * 60 + m2
    return e_m - s_m

def replace_sharp(melody):
    melody = melody.replace('C#', 'c')
    melody = melody.replace('D#', 'd')
    melody = melody.replace('F#', 'f')
    melody = melody.replace('G#', 'g')
    melody = melody.replace('A#', 'a')
    melody = melody.replace('B#', 'b')
    return melody
