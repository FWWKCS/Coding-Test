data = input().split()

x = int(data[0])
y = int(data[1])

w = int(data[2])
h = int(data[3])

print(min(x-0, w-x, y-0, h-y))