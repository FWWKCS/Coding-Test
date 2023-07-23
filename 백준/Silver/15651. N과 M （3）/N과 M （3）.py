def getPermutation(p_list) :
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