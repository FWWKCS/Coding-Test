data = list(map(int,input().split()))
Cards = list(map(int,input().split()))

isFind = False

result = 0

for i in range(0, len(Cards)-2) :
    for j in range(i+1, len(Cards)-1) :
        for k in range(j+1, len(Cards)) :
            if Cards[i] + Cards[j] + Cards[k] < data[1] and result < Cards[i] + Cards[j] + Cards[k] :
                result = Cards[i] + Cards[j] + Cards[k]
            elif Cards[i] + Cards[j] + Cards[k] == data[1] : 
                isFind = True
                break
        if isFind : break
    if isFind : break 

if isFind : print(data[1])
else :
    print(result)
        