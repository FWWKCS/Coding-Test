numlist = []

while True :
    num = int(input())
    if num == -1 : break
    numlist.append(num)


for num in numlist :
    divisor = []

    for i in range(1, num) :
        if num % i == 0 : divisor.append(i)

    if sum(divisor) == num : 
        print(f"{num} = ", end = '')
        for i in range(len(divisor)-1) : 
            print(f"{divisor[i]} +", end = ' ')
        print(divisor[len(divisor)-1])
    else :
        print(f"{num} is NOT perfect.")