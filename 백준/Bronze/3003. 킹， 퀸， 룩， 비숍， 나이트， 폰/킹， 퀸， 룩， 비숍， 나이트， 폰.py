data = input().split()
trueChess = [1,1,2,2,2,8]

for i in range(len(trueChess)) :
    print(trueChess[i] - int(data[i]), end = " ")
