text = input()
target = input()

length = len(target)
stack = []

for t in text:
    stack.append(t)

    if len(stack) < length: continue

    found = True
    for i in range(1, length+1):
        if stack[-i] != target[-i]:
            found = False
            break

    if found:
        for i in range(length): stack.pop()

if len(stack) > 0:
    print(''.join(stack))
else: print('FRULA')