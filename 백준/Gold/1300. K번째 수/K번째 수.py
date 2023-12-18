N = int(input())
k = int(input())

start = 1
end = N*N

answer = -1

while start <= end:
    pivot = (start + end)//2

    count = 0 
    for i in range(1, N+1):
        count += min(N, (pivot-1)//i)

    if count >= k:
        end = pivot - 1
    elif count < k:
        answer = pivot
        start = pivot + 1

print(answer)