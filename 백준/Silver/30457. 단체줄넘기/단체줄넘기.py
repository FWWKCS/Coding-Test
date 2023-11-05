N = int(input())

height = {
    # 키 : 인원수
}

for h in list(map(int, input().split())):
    if h not in height:
        height[h] = 1
    else : height[h] += 1

count = 0
# 키가 같은 사람은 최대 2명씩
for h in height.keys():
    count += min(2, height[h])

print(count)