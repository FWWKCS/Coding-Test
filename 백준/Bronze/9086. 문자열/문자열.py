count = int(input())

flList = []
for i in range(count) :
    sentence = input()
    flList.append(sentence[0]+sentence[-1])

for i in flList: print(i, end = ' ')