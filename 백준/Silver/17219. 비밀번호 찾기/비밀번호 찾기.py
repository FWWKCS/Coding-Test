import sys
input = sys.stdin.readline

N, M = map(int, input().split())
pw_dict = {
    # 사이트 : 비밀번호
}

for _ in range(N) :
    site, pw = input().split()
    pw_dict[site] = pw

for _ in range(M) :
    site = input().rstrip()
    print(pw_dict[site])