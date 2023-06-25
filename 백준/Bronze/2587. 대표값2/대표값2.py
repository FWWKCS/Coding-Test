data = []
for _ in range(5):
    data.append(int(input()))
    
for i in range(4):
    for j in range(i+1, 5):
        if data[i] > data[j] :
            data[i], data[j] = data[j], data[i]
            
print(int(sum(data)/5))
print(data[2])