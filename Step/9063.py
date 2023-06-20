# https://www.acmicpc.net/problem/9063

# 첫째 줄에는 점의 개수 N
# 이어지는 N 줄에는 각 점의 좌표가 두 개의 정수로 한 줄에 하나씩 주어진다.

# 첫째 줄에 N 개의 점을 둘러싸는 최소 크기의 직사각형의 넓이를 출력하시오. 

x = []
y = []

count = int(input())
for r in range(count) :
    data = input().split()
    x.append(int(data[0]))
    y.append(int(data[1]))


x = list(set(x))
y = list(set(y))
x.sort()
y.sort()

xMax = x.pop()
yMax = y.pop()

if len(x) == 0 : xMin = xMax
else : xMin = x[0]

if len(y) == 0 : yMin = yMax
else : yMin = y[0]

print((xMax-xMin)*(yMax-yMin))
