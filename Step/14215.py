# https://www.acmicpc.net/problem/14215

# 세 막대를 이용해서 아래 조건을 만족하는 삼각형을 만들려고 한다.

# 각 막대의 길이는 양의 정수이다
# 세 막대를 이용해서 넓이가 양수인 삼각형을 만들 수 있어야 한다.
# 삼각형의 둘레를 최대로 해야 한다.

# a, b, c가 주어졌을 때, 만들 수 있는 가장 큰 둘레를 구하는 프로그램을 작성하시오. 

# 첫째 줄에 a, b, c (1 ≤ a, b, c ≤ 100)가 주어진다.

# 첫째 줄에 만들 수 있는 가장 큰 삼각형의 둘레를 출력한다.


value = input().split()

lines = [int(value[0]),int(value[1]),int(value[2])]


lines.sort()

if lines[2] >= lines[0] + lines[1] : lines[2] = lines[0] + lines[1] - 1

print(sum(lines))