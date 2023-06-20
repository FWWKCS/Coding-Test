# https://www.acmicpc.net/problem/3009

# 세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 
# 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

# 세 점의 좌표가 한 줄에 하나씩 주어진다. 
# 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

x = []
y = []

for _ in range(3) :
    data = input().split()
    x.append(int(data[0]))
    y.append(int(data[1]))

x.sort()
y.sort()

if x.count(x[0]) == 1 : print(x[0], end = ' ')
else : print(x[2], end = ' ')

if y.count(y[0]) == 1 : print(y[0])
else : print(y[2])