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
                # print(f"지금은 몇번째 바구니? :{count}, {serial[n]}")
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
        serial = renewSerial
        # print(f"{count}회차 결과 : {renewSerial}")
        count += 1

    for num in renewSerial:
        print(num, end = " ")

else :
    for num in serial:
        print(num, end = " ")