def findPassword(depth, word, index) :
    if depth == L : 
        word = ''.join(sorted(word))
        v_count = 0 # 모음 개수
        for v in vowel : 
            if v in word : v_count += 1
        
        c_count = depth - v_count # 자음 개수
    
        if ( v_count == 0 or c_count < 2 ) or word in answer : return
        else :
            answer.add(word)
        
    for l in range(index, len(alphabet)) :
        if alphabet[l] not in word :
            findPassword(depth+1, word+alphabet[l], l)


L, C = map(int, input().split())

alphabet = list(input().split())
alphabet.sort()

vowel = ['a','e','i','o','u']

answer = set()

findPassword(0, '', 0)

answer = sorted(list(answer))

for a in answer : print(a)