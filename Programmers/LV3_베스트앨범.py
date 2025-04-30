def solution(genres, plays):
    genre_play_counts = {}
    genre_song_infos = {}
    for idx in range(len(genres)):
        genre = genres[idx]
        play_count = plays[idx]
        genre_play_counts[genre] = genre_play_counts.get(genre, 0) + play_count
        genre_song_infos.setdefault(genre, []).append((play_count, idx))
    
    best_album = []
    for genre, _ in sorted(genre_play_counts.items(), key = lambda item: -item[1]):
        popular_songs_info = sorted( genre_song_infos[genre], key = lambda info: (-info[0], info[1]) )[0:2]
        popular_songs_idx = [song[1] for song in popular_songs_info]
        best_album.extend(popular_songs_idx)
    return best_album