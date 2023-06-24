value = int(input())

count = 0
num = 665

while count != value :
    num += 1
    if str(num).find('666',0) > -1 : count += 1

print(num)