def operate(depth, add, sub, mul, div, result) :
    global numSet

    if add > 0 : 
        operate(depth+1, add-1, sub, mul, div, result + numSet[depth])
    if sub > 0 :
        operate(depth+1, add, sub-1, mul, div, result - numSet[depth])
    if mul > 0 :
        operate(depth+1, add, sub, mul-1, div, result * numSet[depth])
    if div > 0 : 
        # 음수 / 양수는 양수 // 양수 연산 후 음수로 변환 
        if result < 0 :
            tmp = -(-result//numSet[depth])
        else : 
            tmp = result // numSet[depth]
        operate(depth+1, add, sub, mul, div-1, tmp)

    if depth == len(numSet) : 
        resultSet.add(result)
        return
    

num = int(input())

numSet = list(map(int, input().split()))

add, sub, mul, div = map(int, input().split())

resultSet = set()

operate(1, add, sub, mul, div, numSet[0])

print(max(resultSet))
print(min(resultSet))