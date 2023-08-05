count = 1
while True :
    n0 = int(input())

    if n0== 0 : break

    n1 = 3*n0
    
    n1_is = 'even'

    if n1 % 2 == 0 : 
        n2 = n1 // 2
    else :
        n1_is = 'odd'
        n2 = (n1+1) // 2

    n3 = 3*n2

    n4 = n3 // 9

    print(f'{count}. {n1_is} {n4}')

    count += 1
