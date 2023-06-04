# https://www.acmicpc.net/problem/10812

# 왼쪽으로 i번째 바구니부터 j번째 바구니의 순서 회전 / 기준은 k번째 바구니

# 10 5 / 바구니 개수 N (시작 바구니 : 1부터 N) M번의 회전 시행

# 1 6 4 / 1번째 부터 6번째 까지 회전, 4가 기준이 mid
# 1 2 3 4 5 6 7 8 9 10 -> 4 5 6 1 2 3 7 8 9 10

# 3 9 8 / 3번째 부터 9번째 까지 회전, 8번째 바구니가 mid
# 4 5 6 1 2 3 7 8 9 10 -> 4 5 8 9 6 1 2 3 7 10

# 2 10 5 / 2번째 부터 10번째 까지 회전, 5번째 바구니가 mid
# 4 5 8 9 6 1 2 3 7 10 -> 4 6 1 2 3 7 10 5 8 9

# 1 3 3 / 1번째 부터 3번째 까지 회전, 3번째 바구니가 mid
# 4 6 1 2 3 7 10 5 8 9 -> 1 4 6 2 3 7 10 5 8 9

# 2 6 2 / 2번째 부터 6번째 까지 회전, 2번째 바구니가 mid
# 1 4 6 2 3 7 10 5 8 9 -> i == k : No change


data = input().split()
basket = int(data[0]) # 바구니 개수
trial = int(data[1]) # 시행 횟수 

# 초기 바구니 생성
serial = [num for num in range(1, basket+1)]

if trial != 0 :
    trialArr = [] # 각 시행 방법에 대한 리스트
    for _ in range(trial) :
        mean = input().split()
        i = int(mean[0])-1 # 시작 범위 인덱스
        j = int(mean[1])-1 # 끝 범위 인덱스
        k = int(mean[2])-1 # 기준값 인덱스
        trialArr.append([i,j,k]) # 2차원 리스트 생성

    count = 0
    while count != trial :
        # 작업 시행
        curTrial = trialArr[count] # 현재 회차 시행
        begin = [] # 시작점부터 기준값 전까지의 저장 리스트
        mid = [] # 기준값부터 끝값까지의 저장 리스트
        for n in range(curTrial[0], curTrial[1]+1) :
            if n < curTrial[2] :
                begin.append(serial[n])
            elif n >= curTrial[2] :
                mid.append(serial[n])
        del (serial[curTrial[0]:curTrial[1]+1])

        serial.insert(curTrial[0], mid + begin)

        # 배열 1차원화, list comprehension
        # isinstance(object, type)
        # serial = [item for sublist in serial for item in (sublist if isinstance(sublist, list) else [sublist])]
        renewSerial = []
        for l in range(len(serial)) :
            if isinstance(serial[l], list) : renewSerial += serial[l]
            else : renewSerial += [serial[l]] 
        serial = renewSerial # serial 인계
        
        count += 1

    for num in renewSerial:
        print(num, end = " ")

else :
    for num in serial:
        print(num, end = " ")

