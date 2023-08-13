def getNum(num) :
    global k
    if len(num) >= 2 :
        if A[len(num)-2] == '>' and num[-2] < num[-1] : return
        elif A[len(num)-2] == '<' and num[-2] > num[-1] : return
    
    if len(num) == k+1 :
        numSet.add(num)
        return

    for x in range(10) :
        if str(x) not in num : getNum(num+str(x))


k = int(input())

A = list(input().split())

numSet = set()

getNum('')

print(max(numSet))
print(min(numSet))