import sys
input = sys.stdin.readline

# 유클리드 호제법
def findGCD(A,B) : # A > B
    if A % B == 0 :
        return B
    else :
        return findGCD(B, A % B)
    
a, b = map(int, input().split())

if a > b :
    GCD = findGCD(a, b)
else :
    GCD = findGCD(b, a)

# 최소공배수 = ab / 최대공약수
LCM = a * b // GCD

print(GCD, LCM)