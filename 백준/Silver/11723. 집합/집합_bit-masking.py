import sys
input = sys.stdin.readline

M = int(input())

# 비트마스킹
S = 0 # 공집합
for _ in range(M) :
    operate = input().rstrip()
    if operate not in ('all', 'empty') :
        operate, k = operate.split()

    if operate == 'add' :
        # 1을 k번 L-shift한 이진값을 S에 OR연산
        S |= (1 << int(k)) 
    elif operate == 'remove' :
        # 1을 k번 L-shift한 이진값의 1의 보수를 S에 AND연산
        S &= ~(1 << int(k)) 
    elif operate == 'check' :
        # 1을 k번 L-shift한 이진값과 집합 S를 AND연산
        print(1 if (S & (1 << int(k)) != 0) else 0)
    elif operate == 'toggle' :
        # 1을 k번 L-shift한 이진값과 집합 S를 XOR연산 (x^y = x'y + xy')
        S ^= (1 << int(k))
    elif operate == 'all' :
        # 원소를 비운 후 21번째 이진값을 1로 바꾼 후 1 감산
        S = 0
        S |= (1 << 21) - 1
    elif operate == 'empty' :
        S = 0
