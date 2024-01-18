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
for i in range(1, N):
    if stack[-1] < sequence[i]:
        stack.append(sequence[i])
    else:
        index = binary_search(stack, sequence[i])
        stack[index] = sequence[i]

print(len(stack))