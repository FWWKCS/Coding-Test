children = []

for _ in range(2) :
    children.append(int(input()))

children.sort()
d = abs(children[0] - children[1])

print(children[1]+d)