HEX = input()

length = len(HEX) - 1

degree = 0

DEC = 0

for h in HEX[-1::-1] :
    if h.isdigit() : DEC += int(h) * (16 ** degree)
    elif h == 'A' : DEC += 10 * (16 ** degree)
    elif h == 'B' : DEC += 11 * (16 ** degree)
    elif h == 'C' : DEC += 12 * (16 ** degree)
    elif h == 'D' : DEC += 13 * (16 ** degree)
    elif h == 'E' : DEC += 14 * (16 ** degree)
    elif h == 'F' : DEC += 15 * (16 ** degree)

    degree += 1

print(DEC)