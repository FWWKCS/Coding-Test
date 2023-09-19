while True :
    value = input()
    if value == '0' : break

    is_palindrome = True

    for l in range((len(value) // 2) + 1) :
        if value[l] != value[-(l+1)] :
            is_palindrome = False
            break
    
    if is_palindrome : print('yes')
    else : print('no')