import sys
input = sys.stdin.readline

N, L = map(int, input().split())

zebra = {
    # 검은 줄의 개수: 개체수
}

for _ in range(N):
    lines = input().rstrip()
    count = 0
    current = ''
    pre = ''
    for l in lines:
        current = l
        if current != pre and l == '1':
            count += 1
            pre = l
        else : pre = l

    if count not in zebra: zebra[count] = 1
    else : zebra[count] += 1

info = sorted(list(zebra.items()), reverse=True)
print(info[0][0], info[0][1])