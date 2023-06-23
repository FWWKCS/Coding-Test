value = input().split()

count = int(value[0])
termsNum = int(value[1])

list = input().split()

for i in list :
    if int(i) < termsNum : print(i, end = ' ')