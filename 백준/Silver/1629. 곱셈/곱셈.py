# 나머지 분배법칙
# (AB) % C = [(A % C)(B % C)] % C

def split(A, B, C) :
    if B == 1 : return A % C

    value = split(A, B//2, C)
    if B % 2 == 0 :
        return (value * value) % C
    else :
        return (value * value * A) % C

A, B, C = map(int, input().split())

print(split(A, B, C))