import sys
input = sys.stdin.readline

def search_paper(length, x, y) :
    global paper
    exist = [0,0,0] # 0, 1, -1
    
    for r in range(y, y+length) :
        for c in range(x, x+length) :
            if paper[r][c] == -1 and exist[-1] != 1 : exist[-1] = 1
            elif paper[r][c] == 0 and exist[0] != 1 : exist[0] = 1
            elif paper[r][c] == 1 and exist[1] != 1 : exist[1] = 1

            if sum(exist) > 1 :
                return False
            
    if exist[-1] == 1 : return -1
    elif exist[0] == 1 : return 0
    else : return 1

def split_paper(length, x, y) :
    global count
    if length == 1 : 
        count[paper[y][x]] += 1
        return
    result = search_paper(length, x, y)

    if result is False : 
        # 분열
        new_length = length//3
        for r in range(3) :
            for c in range(3) :
                split_paper(new_length, x+(new_length*r), y+(new_length*c))
    else :
        count[result] += 1

N = int(input())
count = [0,0,0] # 0, 1, -1
paper = [list(map(int, input().split())) for _ in range(N)]

split_paper(N, 0, 0)

print(count[-1])
print(count[0])
print(count[1])