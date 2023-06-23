values = input()
values = values.split()
a = int(values[0])
b = int(values[1])
c = int(values[2])
# A는 고정비용, B는 가변 비용, C는 제품 가격이다.
# 손익분기점 계산식: a + b * x = c * x

# 1000 + 70x = 170x
# 1000 = 100x
# x = 10

# 코드 작성: 이익이 발생하지 않는 경우 -1 출력
if c-b<=0 : print(-1)

# 코드 작성: 최초로 이익이 발생하는 정수형 판매량(> 손익분기점) 출력
else : print(int(a/(c-b))+1)