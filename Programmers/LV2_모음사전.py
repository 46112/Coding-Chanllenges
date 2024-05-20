MAX_WORD_LENGTH = 5

def solution(word):
    global order
    order = 0
    vowels = ['A', 'E', 'I', 'O', 'U']
    
    def dfs(cur_word):
        global order
        order += 1
        
        if(cur_word == word):
            return True
        if(len(cur_word) >= MAX_WORD_LENGTH):
            return False
        for vowel in vowels:
            if(dfs(cur_word + vowel)):
                return True
        
        
    for vowel in vowels:
        if(dfs(vowel)):
            return order
    
    return -1

# dfs

    