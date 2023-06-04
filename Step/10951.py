# # https://www.acmicpc.net/problem/10951

# 입력은 여러 개의 테스트 케이스로 이루어져 있다.

# 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)


# hint : readlines()

# 온라인 테스트 파일을 가져와 대입시키는 방식으로 답을 판정하는 백준 특징 이용
# 이 방법 외에 예외처리로 해결하는 방법 존재

import sys
lines = sys.stdin.readlines()
for line in lines:
    A, B = map(int, line.split())
    print(A,B)


    