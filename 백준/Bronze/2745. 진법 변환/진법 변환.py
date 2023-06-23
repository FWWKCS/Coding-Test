data = input().split()

value = data[0]
notation = int(data[1])

result = 0
position = 0 # N[k] * B ^ pos

for v in value[-1::-1]:
    if 48 <= ord(v) and ord(v) <= 57 : 
        result += int(v) * (notation ** position)
    elif 65 <= ord(v) and ord(v) <= 90 : # A ~ Z
        result += (ord(v)-55) * (notation ** position)
    
    position += 1

print(result)