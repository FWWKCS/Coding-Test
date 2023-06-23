import math

input = input().split()

climb = int(input[0])
slide = int(input[1])
V = int(input[2])

# V-A = (A-B)*Day
# Day가 소수이면 올림 (잔여 거리 고려)

# Day = (V-A)/(A-B)
Day = (V-climb)/(climb-slide)

# 최종 목표
print(math.ceil(Day)+1)