def getPermutation(p_list) :
    global p_set
    if len(p_list) == r :
        p_tuple = tuple(sorted(p_list))
        if p_tuple not in p_set :
            p_set.add(tuple(p_list))
            print(' '.join(str(e) for e in p_list))

        return
    
    for k in range(1,n+1) :
        if k not in p_list :
            p_list.append(k)
            getPermutation(p_list)
            p_list.pop()

# 순열 Permutation
n, r = map(int, input().split()) # nPr

p_list = []
p_set = set() # 중복 제거

for k in range(1,n+1) :
    p_list.append(k)
    getPermutation(p_list)
    p_list.pop()