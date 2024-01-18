N = int(input())
sequence = list(map(int, input().split()))

def binary_search(stack, find_value):
    s = 0
    e = len(stack)-1
    pivot = (s+e) // 2

    while s <= e:
        pivot = (s+e) // 2
        if stack[pivot] < find_value:
            s = pivot + 1
        elif stack[pivot] > find_value:
            e = pivot - 1
        else:
            return pivot
        
    return s

stack = [sequence[0]]
pos = [1 for _ in range(N)]

for i in range(1, N):
    if stack[-1] < sequence[i]:
        stack.append(sequence[i])
        pos[i] = len(stack)
    else:
        index = binary_search(stack, sequence[i])
        stack[index] = sequence[i]
        pos[i] = index+1

print(len(stack))

# find route
index = pos.index(len(stack))
route = [sequence[index]]
current = len(stack)

for i in range(index-1, -1, -1):
    if pos[i] == current - 1:
        route.append(sequence[i])
        current -= 1

print(*route[-1::-1])