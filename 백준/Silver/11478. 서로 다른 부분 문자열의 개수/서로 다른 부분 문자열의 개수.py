data = input()

elementLen = 1

total = [] # 총 개수

while elementLen <= len(data) :
    for i in range(1, len(data)+1) :
        total.append(data[i-1:i-1+elementLen])

    elementLen += 1

print(len(set(total)))