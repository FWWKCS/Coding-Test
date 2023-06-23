count = 1
save = []
while count != 10:
    num = int(input())
    save.append(num)
    count += 1

for i in range(len(save)):
    if save[i] == max(save):
        print(max(save))
        print(i+1)
        break