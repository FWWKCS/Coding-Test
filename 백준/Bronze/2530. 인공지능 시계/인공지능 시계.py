h, m, s = map(int, input().split())
delay = int(input())

dh = delay // 3600
delay -= dh * 3600
dm = delay // 60
delay -= dm * 60
ds = delay

# 변화량 가산
h += dh
m += dm
s += ds

# 캐리 연산
m += s // 60
s = s % 60

h += m // 60
m = m % 60

h = h % 24

print(h, m, s)