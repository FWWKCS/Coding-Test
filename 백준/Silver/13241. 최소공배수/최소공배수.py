# 최소공배수(LCM) = 두 자연수의 곱 / 최대공약수(GCD)

# 유클리드 호제법
# 참조 : https://myjamong.tistory.com/138

# 두 수 A, B에 대하여 A > B일때, A % B = r0 과 
# B, r0 에 대하여 B % r0 = r1, 
# r0, r1 에 대하여 r1 % r0 = r2, .. 를 반복하여 rn이 0이 될때
# r0는 최대 공약수(GCD)가 된다

A, B = map(int,input().split())

mul = A*B
R = 1 
while R != 0 :
    R = A % B
    A, B = B, R

GCD = A
LCM = mul // GCD
print(LCM)