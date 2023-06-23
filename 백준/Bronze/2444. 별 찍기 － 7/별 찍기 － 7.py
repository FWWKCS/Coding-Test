num = int(input())

# 피라미드꼴 생성
for i in range(1, num+1):
    print(" " * (num-i), end="")
    print('*' * (2*i-1), end="\n")

# 역피라미드꼴 생성
for i in range(num-1, 0, -1):
    print(" " * (num-i), end="")
    print('*' * (2*i-1), end="\n")