T = int(input())

def check_distance(array) : 
    total = 0
    for i in range(len(array)-1) :
        for j in range(i+1, len(array)) :
            for l in range(4) :
                if array[i][l] != array[j][l] :
                    total += 1

    return total

for _ in range(T) :
    N = int(input())
    # 어느 하나라도 같은 성향인 사람이 3명이상이 되면 최단거리는 무조건 0
    # 비둘기집 원리
    MBTI_arr = list(input().split())

    if N > 32 : 
        print(0)
        continue
    
    distance = 1000 # 거리의 최솟값

    for x in range(N-2) :
        for y in range(x+1, N-1) :
            for z in range(y+1, N) :
                selected = [MBTI_arr[x], MBTI_arr[y], MBTI_arr[z]]
                distance = min(distance, check_distance(selected))
    
    print(distance)