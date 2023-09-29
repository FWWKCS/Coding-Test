# https://hongcoding.tistory.com/60

import math
import sys
input = sys.stdin.readline

testcase = int(input())
for _ in range(testcase) :
    clothes_dict = {
        # 종류 : 개수
    }

    total = 1
    n = int(input())
    # 딕셔너리 구성 추가
    for _ in range(n) :
        name, parts = input().split()
        if parts in clothes_dict : clothes_dict[parts] += 1
        else : clothes_dict[parts] = 1

    for v in clothes_dict.values() :
        total *= v+1

    print(total-1)