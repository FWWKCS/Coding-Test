logCount = int(input())

userSet = set() # 중복 방지

total = 0

for k in range(logCount) :
    data = input()
    if data == 'ENTER' and k != 0 :
        total += len(userSet) # 정산
        userSet = set() # 입장시 초기화
        
    elif data != 'ENTER' :
        userSet.add(data)
    
    if k == logCount - 1 :        
        total += len(userSet) # 마지막 정산

print(total)