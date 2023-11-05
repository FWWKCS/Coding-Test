import sys

N = int(input())
string = input()

# 양쪽 부분의 문자의 개수가 짝수일 것
letters = [0 for _ in range(26)]

for l in string[:N//2]:
    letters[ord(l)-97] += 1

if N % 2 != 0 :
    for l in string[(N//2)+1:]:
        letters[ord(l)-97] += 1
else :
    for l in string[(N//2):]:
        letters[ord(l)-97] += 1

for c in letters:
    if c % 2 != 0 :
        print('No')
        sys.exit()

print('Yes')       