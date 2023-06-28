def binary_search(findValue, array) :
    start = 0
    end = len(array) - 1
    while start <= end :
        pivot = (start + end) // 2
        if array[pivot] == findValue : return 1
        elif array[pivot] > findValue : end = pivot - 1
        else : start = pivot + 1
    
    return 0

cardsCount = int(input())

cards = list(map(int,input().split()))
cards = sorted(cards)

findCount = int(input())

findCards = list(map(int, input().split()))

for f in findCards :
    print(binary_search(f, cards), end = ' ')