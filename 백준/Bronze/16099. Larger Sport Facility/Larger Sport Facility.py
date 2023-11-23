T = int(input())
for _ in range(T):
    lt, wt, le, we = map(int, input().split())
    if le*we > lt*wt: print('Eurecom')
    elif le*we < lt*wt: print('TelecomParisTech')
    else: print('Tie')