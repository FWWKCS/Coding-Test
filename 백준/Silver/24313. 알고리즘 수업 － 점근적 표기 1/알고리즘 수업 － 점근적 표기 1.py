a1, a0 = list(map(int,input().split()))

c = int(input())

n0 = int(input())

# 지정한 n0를 최솟값으로 n0보다 큰 모든 값에 대하여
# 각각의 함수 f(n)과 g(n)의 관계가 O(g(n)) 정의를 만족

# 이 조건을 만족하려면
# 함숫값이 최솟값인 n0에서 f(n0) <= cg(n0) 를 만족해야한다
# 동시에 g(n)의 기울기가 f(n)의 기울기보다 커야한다

# 위 조건을 동시에 만족하면 n0이상의 모든 값에서 O(g(n))의 정의를 만족한다

if a1*n0+a0 <= c*n0 and a1 <= c : print(1)
else : print(0)  