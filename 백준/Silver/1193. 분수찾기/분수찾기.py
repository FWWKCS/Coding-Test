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