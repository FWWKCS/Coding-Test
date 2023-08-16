total = 1
for _ in range(3) :
    total *= int(input())

total = str(total)

count = [0] * 10

for t in total :
    count[int(t)] += 1

for c in count : print(c)

