data = input().split()

divisor = []
num = int(data[0])
index = int(data[1])

for i in range(1, num+1) :
    if num % i == 0 : divisor.append(i)

try :
    print(divisor[index-1])
except :   
    print(0)
