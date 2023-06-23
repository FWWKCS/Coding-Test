word = input()

# 문자 -, = 가 아닌 각 문자를 확인

count = 0

# 반복문의 인덱스를 임의로 변경시키려면 while을 사용할 것
# for문의 index는 임의로 변화시켜도 범위값에 의해 초기화됨
index = 0
while index < len(word) :
    # 문자열 인덱싱의 범위가 문자열 인덱스를 벗어난 부분은 비우고
    # 유효한 부분만 출력하기에 인덱스 오류를 내지않음
    
    if word[index : index+2] in ('c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=') :
        # print(f"특수 케이스 발견 : {word[index : index+2]}")
        count += 1
        index += 2 # word 인덱스 한 칸 뛰어넘기
        continue
    # 변환 문자가 3글자인 특수한 경우 
    elif word[index : index+3] == 'dz=' :
        # print(f"특수 케이스 발견 : {word[index : index+3]}")
        count += 1
        index += 3
        continue

    if word[index] not in ('-', '=') :
        # print(f"특수 케이스 아님 : {word[index]}")
        count += 1
        index += 1
        continue
    
    index += 1

print(count)