# https://www.acmicpc.net/problem/1193

# 행이 분자, 열이 분모인 2차원 배열꼴 테이블에 대하여

# 열을 1 증가
# 좌측 하단 대각선 방향으로 이동
# 행을 1증가
# 우측 상단 대각선 방향으로 이동

# 위 과정을 반복

# findIndex = int(input())

# row = 1 # 처음 행 (분수 생성시 분자)
# col = 1 # 처음 열 (분수 생성시 분모)

# count = 1

# while (True):
#     # 열을 1 증가
#     col += 1
#     count += 1
#     if count == findIndex : break

#     # 좌측 하단 대각선 방향으로 col이 1일 때까지 이동
#     while (col != 1) :
#         row += 1
#         col -= 1
#         count += 1
#         if count == findIndex : break
#     if count == findIndex : break

#     # 행을 1 증가
#     row += 1
#     count += 1
#     if count == findIndex : break

#     # 우측 상단 대각선 방향으로 row가 1일 때까지 이동
#     while (row != 1) :
#         col += 1
#         row -= 1
#         count += 1
#         if count == findIndex : break
#     if count == findIndex : break

# print(f"{row}/{col}")

# 시간 초과 ( over 0.5s )

# -----------------------------------------

# 처음 1층 = 1 ( 1개 )
# 2층 = 2 ~ 3 ( 2개 )
# 3층 = 4 ~ 6 ( 3개 )
# 4층 = 7 ~ 10 ( 4개 )

# 1, 2, 4, 7, 11, ...

# n층의 요소개수 = n개

# 홀수 층은 하강 ( col 감소, row 증가 )
# 짝수 층은 상승 ( col 증가, row 감소 )

findIndex = int(input())

sequence = 1
cd = 1

while (sequence + cd <= findIndex) :
    sequence += cd
    cd += 1

# cd가 홀수인지 짝수인지에 따라 해당 층 시작점을 구분

count = sequence # sequence부터 증가
row = 0 # 행
col = 0 # 열

if cd % 2 == 0 : # 짝수면 1행 cd열 부터, 좌측하단 대각선 방향
    row = 1
    col = cd
    while (count != findIndex) :
        row += 1
        col -= 1
        count += 1

else : # 홀수면 cd행 1열 부터, 우측상단 대각선 방향
    row = cd
    col = 1
    while (count != findIndex) :
        row -= 1
        col += 1
        count += 1

print(f"{row}/{col}")