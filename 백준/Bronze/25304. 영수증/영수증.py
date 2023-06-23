total = int(input())
kinds = int(input())
sum = 0

for i in range(kinds):
    element = input().split()
    sum += int(element[0]) * int(element[1])
    
if total == sum :
    print('Yes')
else : print('No')