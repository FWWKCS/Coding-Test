cards = []
color_dict = {
    # 색깔 : 개수
}
num_dict = {
    # 숫자 : 개수
}

for _ in range(5) :
    color, num = input().split()
    cards.append((color, int(num)))

    if color in color_dict : color_dict[color] += 1
    else : color_dict[color] = 1

    if int(num) in num_dict : num_dict[int(num)] += 1
    else : num_dict[int(num)] = 1

result = 0
isListed = False
# 숫자 연속성 검사, 단 5개의 서로 다른 숫자로 존재할 때만
if len(num_dict) == 5 :
    isListed = True
    numList = sorted(num_dict.keys())
    for n in range(1,5) :
        if numList[n] != numList[n-1] + 1 :
            isListed = False
            break


# 1. 카드 5장 모두 같은 색이고, 숫자가 연속적인 경우
if len(color_dict) == 1 and isListed : 
    result = 900 + max(num_dict.keys())

# 2. 카드 5장 중 4장의 숫자가 동일한 경우
elif len(num_dict) == 2 and 4 in num_dict.values() :
    val = 0
    for n in num_dict.keys() :
        if num_dict[n] > 1 : 
            val = n
    
    result = 800 + val

# 3. 카드 5장 중 3장의 숫자가 같고, 나머지 2장도 숫자가 같은 경우
elif len(num_dict) == 2 and 3 in num_dict.values() :
    a = 0 # 3장의 숫자
    b = 0 # 2장의 숫자
    for n in num_dict.keys() :
        if num_dict[n] == 3 : a = n
        elif num_dict[n] == 2 : b = n

    result = 700 + (10 * a) + b

# 4. 5장의 카드 색깔이 모두 같은 경우
elif len(color_dict) == 1 :
    result = 600 + max(num_dict.keys())

# 5. 카드 5장의 숫자가 연속적인 경우
elif isListed :
    result = 500 + max(num_dict.keys())

# 6. 카드 3장의 숫자가 같은 경우
elif len(num_dict) == 3 and 3 in num_dict.values() :
    val = 0
    for n in num_dict.keys() :
        if num_dict[n] == 3 : val = n

    result = 400 + val

# 7. 카드 2장의 숫자가 같고, 또 다른 2장의 숫자가 같은 경우
elif len(num_dict) == 3 and max(num_dict.values()) == 2 :
    a = 0
    b = 0
    for n in num_dict.keys() :
        if num_dict[n] == 2 :
            if a == 0 : a = n
            else : b = n

    if a > b :
        result = 300 + (10*a) + b
    else :
        result = 300 + (10*b) + a

# 8. 카드 5장 중 2장의 숫자가 같은 경우
elif len(num_dict) == 4 :
    val = 0
    for n in num_dict.keys() :
        if num_dict[n] == 2 : 
            val = n
            break
    
    result = 200 + val

# 9. 위 어떤 경우에도 해당하지 않는 경우
else :
    result = 100 + max(num_dict.keys())


print(result)