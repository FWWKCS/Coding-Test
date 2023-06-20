# https://www.acmicpc.net/problem/10101

# 삼각형의 세 각을 입력받은 다음, 

# 세 각의 크기가 모두 60이면, Equilateral
# 세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
# 세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
# 세 각의 합이 180이 아닌 경우에는 Error

# 를 출력하는 프로그램을 작성하시오.

angle = []

for _ in range(3) :
    angle.append(int(input()))

if sum(angle) != 180 : print('Error')
else :
    if angle.count(60) == 3 : print('Equilateral')
    elif len(list(set(angle))) == 2 : print('Isosceles')
    else : print('Scalene')
