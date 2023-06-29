def get_GCD (value) :
    # 입력한 수의 최대공약수를 구하는 함수
    tmp = { 
        # 임시 딕셔너리    
    }
    if value == 1 : 
        tmp[1] = 1
        return tmp
    
    while value != 1 :
        opr = 2
        while True :
            if value % opr == 0 : break
            else : opr += 1
        
        if opr in tmp : tmp[opr] += 1
        else : tmp[opr] = 1

        value /= opr
    
    return tmp

A = {
    # 첫 수의 최대공약수 딕셔너리
}

B = {
    # 두번째 수의 최대공약수 딕셔너리
}

total = {
    # A, B의 최소 공배수 딕셔너리
}

data = [] # A, B 입력값

testCase = int(input())

for _ in range(testCase) :
    data.append(list(map(int,input().split())))

result = [] # print least common multiple

# 데이터 처리 영역
for d in data :
    A, B = get_GCD(d[0]), get_GCD(d[1])
    for a in A.keys() :
        total[a] = A[a]

    for b in B.keys() :
        if b in total : total[b] = max(total[b], B[b])
        else : total[b] = B[b]

    # 최소공배수 계산
    LCM = 1
    for t in total.keys() :
        LCM *= t**total[t]

    result.append(LCM)

    total.clear()

for L in result : print(L)


