N = int(input())
pos = list(map(int, input().split()))

pos_dict = {
    # 좌표 : 순서
}
sorted_pos = sorted(list(set(pos)))

# 딕셔너리 값 추가
for k in range(len(sorted_pos)) :
    pos_dict[sorted_pos[k]] = k

for p in pos :
    print(pos_dict[p], end = ' ')
