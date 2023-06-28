def binary_search(findValue, array) :
    start = 0
    end = len(array) - 1
    while start <= end :
        pivot = (start + end) // 2
        if array[pivot] == findValue : return 1
        elif array[pivot] > findValue : end = pivot - 1
        else : start = pivot + 1
    
    return 0

setCount, findCount = map(int, input().split())

Elements = []
findElements = []

for _ in range(setCount) :
    Elements.append(input())

Elements = sorted(Elements)

for _ in range(findCount) :
    findElements.append(input())

found = 0
for f in findElements :
    found += binary_search(f, Elements)

print(found)


