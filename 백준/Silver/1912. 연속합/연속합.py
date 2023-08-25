import sys
input = sys.stdin.readline

N = int(input())
sequence = list(map(int, input().split()))

memoization = [sequence[0]] + [0] * (len(sequence)-1)
maxValue = sequence[0] # 출력할 최댓값

# 점화식 : 자신을 포함한 최대누적합 vs 자기자신
for i in range(1,len(sequence)) :
    memoization[i] = max(memoization[i-1] + sequence[i], sequence[i])

    if memoization[i] > maxValue : # 최대 연속합 초기화 
        maxValue = memoization[i]
    
print(maxValue)