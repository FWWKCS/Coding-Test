data = input()

constList = []
constructor = 0

num = int(data)
length = len(data)

e_sum = 0

for n in range(num,1,-1) :
    constructor = n # 생성자
    str_n = str(n) # 생성자 형 변환
    for e in range(len(str_n)) :
        e_sum += int(str_n[e])
    
    if constructor + e_sum == num : 
        constList.append(constructor)
    
    e_sum = 0

if len(constList) > 0 : print(min(constList))
else : print(0)       