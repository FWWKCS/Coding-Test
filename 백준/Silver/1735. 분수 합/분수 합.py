def get_GCD (v0, v1) :
    mul = v0 * v1
    D0, D1 = max(v0, v1), min(v0, v1)
    R = 1
    while R != 0 :
        R = D0 % D1
        D0, D1 = D1, R

    return D0 # GCD


# val = [numerator, denominator]

A = list(map(int,input().split()))
B = list(map(int,input().split()))

# 분모의 최소공배수 찾기
mul = A[1] * B[1]
GCD = get_GCD(A[1],B[1])
LCM = mul // GCD

# 최소공배수로 나눠지는 수를 분자에 곱연산
A[0] *= LCM // A[1]
B[0] *= LCM // B[1]

total = [A[0]+B[0], LCM]

# 기약분수화 ( 분자 분모가 서로소 )
# 두 수의 최대공약수로 나눔
GCD = get_GCD(total[0], total[1])
print(total[0]//GCD, total[1]//GCD)