code = '9780921418'

for _ in range(3) :
    code += input()

total = 0

for c in range(13) :
    if c % 2 == 1 :
        total += int(code[c]) * 3
    else :
        total += int(code[c]) * 1

print(f'The 1-3-sum is {total}')