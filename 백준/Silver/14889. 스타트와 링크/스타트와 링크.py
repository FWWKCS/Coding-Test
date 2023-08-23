import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def makeTeam(index, depth) :
    global ability, start, link, gap

    if depth == N // 2 :
        start_score = 0
        link_score = 0

        # 남은 팀을 link팀에 채우기
        for i in range(N) :
            if i not in start : link.append(i)        

        for k in range((N//2)-1) :
            for l in range(k, N//2) :
                start_score += ability[start[k]][start[l]] + ability[start[l]][start[k]]
        
        for k in range((N//2)-1) :
            for l in range(k, N//2) :
                link_score += ability[link[k]][link[l]] + ability[link[l]][link[k]]

        gap = min(gap, abs(start_score - link_score))

        # link 비우기 (복구)
        link = []
        return
    
    for i in range(index, N) :
        # start팀만 N // 2 만큼 채우기 
        start.append(i)
        makeTeam(i+1, depth+1)
        # 복구
        start.pop()

N = int(input())

ability = [list(map(int,input().split())) for _ in range(N)]

start = []
link = []
gap = 999999

makeTeam(0, 0)

print(gap)