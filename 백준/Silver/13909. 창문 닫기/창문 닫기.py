# 시뮬레이션 코드

# count = int(input())

# window = "0"*count

# print(window)

# for k in range(1,count+1) :
#     window = list(window)
#     i = 1
#     while i*k <= count :
#         if window[i*k-1] == '0' : window[i*k-1] = '1'
#         else : window[i*k-1] = '0'

#         i += 1

#     print(f'k = {k}, window = {window}')

# window = ''.join(s for s in window)

# print(window, window.count('1'))

# 3 : 1
# 4 ~ 8 : 2
# 9 ~ 15 : 3
# 16 ~ 24 : 4
# 25 ~ 35 : 5

# n^2 <= k < (n+1)^2 에서 k의 창문 개수는 n개

import math

N = int(input())

print(int(math.sqrt(N)))