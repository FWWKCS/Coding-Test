import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

# 메모이제이션 기록
def note(numSet) :
    global memoization
    if len(numSet) == 3 :
        a, b, c = numSet

        if a <= 0 or b <= 0 or c <= 0 : 
            memoization[(a,b,c)] = 1
            return
        elif a < b and b < c :
            memoization[(a,b,c)] = memoization[(a,b,c-1)] + memoization[(a,b-1,c)] - memoization[(a,b-1,c)]
            return
        else :
            memoization[(a,b,c)] = memoization[(a-1,b,c)] + memoization[(a-1,b-1,c)] + memoization[(a-1,b,c-1)] - memoization[(a-1,b-1,c-1)]
            return
    
    for i in range(21) :
        note(numSet+[i])

memoization = {
    # ( a, b, c ) : value
}

note([])

while True :
    a, b, c = map(int, input().split())
    if a == -1 and b == -1 and c == -1 : break

    if a <= 0 or b <= 0 or c <= 0 :
        value = 1
    elif a > 20 or b > 20 or c > 20 :
        value = memoization[(20,20,20)]
    else :
        value = memoization[(a,b,c)]
    print(f'w({a}, {b}, {c}) = {value}')