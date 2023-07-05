N = int(input())

Dance = {'ChongChong'}
    # 춤추는 사람들의 집합 , ChongChong은 기본값

for _ in range(N) :
    A, B = input().split()
    if A in Dance : Dance.add(B)
    elif B in Dance : Dance.add(A)
    elif A in Dance and B in Dance : pass
    
print(len(Dance))