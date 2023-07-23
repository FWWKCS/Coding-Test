# 비내림차순 : 각 수열의 각각의 원소가 바로 앞에 있는 원소보다 크거나 같을 경우

def getPermutation(p_list) :
    for k in range(1,len(p_list)) :
        if p_list[k-1] > p_list[k] : return

    if len(p_list) == r :
        print(' '.join(str(e) for e in p_list))
        return
    
    for k in range(1,n+1) :
        p_list.append(k)
        getPermutation(p_list)
        p_list.pop()

# 순열 Permutation
n, r = map(int, input().split()) # nPr

p_list = []

for k in range(1,n+1) :
    p_list.append(k)
    getPermutation(p_list)
    p_list.pop()