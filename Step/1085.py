# 한수는 지금 (x, y)에 있다. 
# 직사각형은 각 변이 좌표축에 평행하고, 
# 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다. 
# 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

# 첫째 줄에 x, y, w, h가 주어진다. x, y, w, h는 정수

data = input().split()

x = int(data[0])
y = int(data[1])

w = int(data[2])
h = int(data[3])

print(min(x-0, w-x, y-0, h-y))