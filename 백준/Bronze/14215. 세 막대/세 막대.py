value = input().split()

lines = [int(value[0]),int(value[1]),int(value[2])]


lines.sort()

if lines[2] >= lines[0] + lines[1] : lines[2] = lines[0] + lines[1] - 1

print(sum(lines))