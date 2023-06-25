count = int(input())
data = []
for _ in range(count):
    data.append(int(input()))
    
for i in range(count-1):
    for j in range(i+1, count):
        if data[i] > data[j] : 
            data[i], data[j] = data[j], data[i]
            
for d in data: 
    print(d)