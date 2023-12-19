import sys
input = sys.stdin.readline

def bin_search(insert_value):
    global S
    start = 0
    end = len(S)-1
    
    while start <= end:
        pivot = (start+end)//2
        if S[pivot] < insert_value: 
            start = pivot + 1
        elif S[pivot] > insert_value:
            end = pivot - 1
        else: 
            return pivot
    
    return start

N = int(input())
A = list(map(int, input().split()))

S = [A[0]]

for a in A[1:]:
    if S[-1] < a: S.append(a)
    else:
        index = bin_search(a)
        S[index] = a

print(len(S))