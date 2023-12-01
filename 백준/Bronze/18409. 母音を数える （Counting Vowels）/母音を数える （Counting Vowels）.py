N = int(input())
S = input()

vowel = {'a','i','o','e','u'}
count = 0
for s in S:
    if s in vowel: count += 1
        
print(count)