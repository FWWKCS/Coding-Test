wholePaper = [[0 for _ in range(100)] for _ in range(100)] # 0부터 100까지

papers = int(input())

for d in range(papers) : 
    data = input().split()
    x = int(data[0])
    y = int(data[1])
    for r in range(x, x+10) :
        for c in range(y, y+10) :
            wholePaper[r][c] = 1

result = 0

for r in range(len(wholePaper)):
    if wholePaper[r].count(1) != 0 : result += wholePaper[r].count(1)

print(result)