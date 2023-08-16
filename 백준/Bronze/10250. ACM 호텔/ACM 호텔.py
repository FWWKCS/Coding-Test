testCase = int(input())

for _ in range(testCase) :
    H, W, N = map(int, input().split())

    hotel = [[False for _ in range(W)] for _ in range(H)]

    count = 1
    room = ''
    for w in range(1,W+1) :
        for h in range(1,H+1) :
            if N == count : 
                room += str(h)
                if w < 10 :
                    room += '0' + str(w)
                else : 
                    room += str(w)
            
            count += 1

    print(room)
