N = int(input())
channel = []

for _ in range(N) :
    channel.append(input())

solution = '' # 출력 형식
target = 0 # 시작점

# KBS1의 위치를 정렬

# 보편적인 상태 : 1로 위치 추적 후 4로 끌어올리기
while channel[target] != 'KBS1' :
    # 도중 target+1이 KBS2이고 KBS1보다 먼저 만나면 3번 실행 
    if channel[target+1] == 'KBS2' :
        solution += '3'
        channel[target], channel[target+1] = channel[target+1], channel[target]
        target += 1
    # 특수 조건
    elif channel[1] == 'KBS1' :
        solution += '3'
        channel[target], channel[target+1] = channel[target+1], channel[target]
        target += 1
        break
    else :
        solution += '1'
        target += 1

while channel[0] != 'KBS1' :
    solution += '4'
    channel[target], channel[target-1] = channel[target-1], channel[target]
    target -= 1


# KBS2의 위치를 정렬
while channel[target] != 'KBS2' :
    # 특수 조건
    if channel.index('KBS2') == 2 and target == 1:
        solution += '3'
        channel[target], channel[target+1] = channel[target+1], channel[target]
        target += 1
        break

    # 보편적인 상태 : 1로 위치 추적 후 4로 끌어올리기
    else :
        solution += '1'
        target += 1

while channel[1] != 'KBS2' :
    solution += '4'
    channel[target], channel[target-1] = channel[target-1], channel[target]
    target -= 1

print(solution)

