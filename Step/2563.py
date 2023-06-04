# https://www.acmicpc.net/problem/2563

# 입력하는 한 점은 정사각형 좌측하단의 좌표값

# 겹치는 넓이를 구하는것은 많은 변수가 발생하는 어려움 존재

# 100 X 100의 2차월 배열에서 할당되는 곳을 1, 여백을 0으로 놓고
# 1의 총 개수를 출력

# 연산량이 커지지만, 여러번 겹치는 부분의 어려움을 해결할 수 있음

wholePaper = [[0 for _ in range(100)] for _ in range(100)] # 0부터 100까지

papers = int(input())

for d in range(papers) : 
    data = input().split()
    x = int(data[0])
    y = int(data[1])
    for r in range(x, x+10) : # x 자신의 값을 포함하여 10번을 수행
        for c in range(y, y+10) :
            wholePaper[r][c] = 1

result = 0

for r in range(len(wholePaper)):
    if wholePaper[r].count(1) != 0 : result += wholePaper[r].count(1)

print(result)

