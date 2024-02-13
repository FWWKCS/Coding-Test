while True:
    value = int(input())
    if value == 0: break
    
    if value % 42 == 0: print('PREMIADO')
    else: print('TENTE NOVAMENTE')