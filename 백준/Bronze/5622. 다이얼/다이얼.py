dial = ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']

data = input()
time = 0

for i in range(len(data)):
    for j in range(len(dial)):
        if dial[j].find(data[i]) >= 0 :
            time += j + 3


print(time)