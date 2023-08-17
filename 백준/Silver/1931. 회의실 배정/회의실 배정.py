import sys
input = sys.stdin.readline

N = int(input())

schedule = []
choose = [] # 선택된 스케줄

for _ in range(N) :
    schedule.append(tuple(map(int, input().split())))

# 시간 오름차순 정렬 ( 1순위 : 종료시간; 가장 빨리 끝나는 순, 2순위 : 시작시간순 )
schedule = sorted(schedule, key = lambda x : (x[1], x[0]))

choose.append(schedule[0])
current = schedule[0]
if N > 1 :
    for s in schedule[1:] :
        # 시작시간이 최근 선택한 스케줄의 중간에 껴있는 경우
        if current[0] <= s[0] and s[0] < current[1] : continue
        # 최근 선택한 스케줄보다 시작시간이 작은 경우 ( 종료시간에 의해 뒤로 밀린 경우 )
        if s[0] < current[0] : continue

        choose.append(s)
        current = s

    print(len(choose))
else :
    print(len(schedule))