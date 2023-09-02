word = list(input())

for i in range(len(word)) :
    if ord(word[i]) <= 90 :
        word[i] = chr(ord(word[i]) + 32)
    else :
        word[i] = chr(ord(word[i]) - 32)

print(''.join(word))