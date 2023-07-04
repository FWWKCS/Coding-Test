T = int(input())

A = 0 # 5분
B = 0 # 1분
C = 0 # 10초

A = T // 300
T -= A * 300
B = T // 60
T -= B * 60
C = T // 10
T -= C * 10

if T != 0 : print(-1)
else : print(A, B, C)