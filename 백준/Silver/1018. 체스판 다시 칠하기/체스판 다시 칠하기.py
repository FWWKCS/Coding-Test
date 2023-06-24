row, col = list(map(int,input().split()))

TotalSet = []
TestSet = []

redraw = [] # 각 케이스별 색칠 횟수 리스트
rdCount = 0

TargetSet = [['BWBWBWBW',
              'WBWBWBWB',
              'BWBWBWBW',
              'WBWBWBWB',
              'BWBWBWBW',
              'WBWBWBWB',
              'BWBWBWBW',
              'WBWBWBWB'],     # dataSet 1; Black으로 시작          
             ['WBWBWBWB',
              'BWBWBWBW',
              'WBWBWBWB',
              'BWBWBWBW',
              'WBWBWBWB',
              'BWBWBWBW',
              'WBWBWBWB',
              'BWBWBWBW']]     # dataSet 2; White로 시작

for _ in range(row) : TotalSet.append(input())

for r in range(7, row) :
    for c in range(7, col) :
        for d in range(8): # 샘플 체스판 추출
            TestSet.append(TotalSet[r-7+d][c-7:c+1])

        # 체스판 최소 색칠 연산
        for t in range(2) : # 2가지 경우를 연산
            for p in range(8):
                for q in range(8) :
                    if TargetSet[t][p][q] != TestSet[p][q] :
                        rdCount += 1

            redraw.append(rdCount)
            rdCount = 0

        TestSet = [] # 샘플 체스판 초기화

print(min(redraw))
        
