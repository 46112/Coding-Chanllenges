import re

class File:
    def __init__(self, file_name, head, number, tail, index):
        self.file_name = file_name
        self.head = head
        self.number = number
        self.tail = tail
        self.index = index

def solution(files):
    file_objects = []
    pattern = re.compile('([^0-9]+)([0-9]{1,5})(.*)')
        
    for idx, file_name in enumerate(files):
        match = pattern.match(file_name)
        if match:
            head = match.group(1)
            number = int(match.group(2))
            tail = match.group(3)
            file_objects.append(File(file_name, head, number, tail, idx))
        else:
            raise Exception('Not match with pattern')
            
    sorted_files = sorted(file_objects, key = lambda file: (file.head.lower(), file.number, file.index))
    sorted_files_name = [file.file_name for file in sorted_files]    
    return sorted_files_name
