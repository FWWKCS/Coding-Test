input = input()

# print(len(input)//2, input[len(input)//2])

result = 1

for i in range(len(input)//2): # 검증 범위
    if input[i] == input[len(input)-i-1] : continue
    else : 
        result = 0
        break

print(result)