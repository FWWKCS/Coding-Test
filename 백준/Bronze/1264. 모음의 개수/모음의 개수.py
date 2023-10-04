import sys
input = sys.stdin.readline

vowel = ['a','e','i','o','u']

while True :
    text = input().rstrip()
    if text == '#' : break 
    count = 0

    for v in vowel:
        count += text.count(v)
        count += text.count(v.upper())

    print(count)