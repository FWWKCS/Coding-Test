def getNotationValue(remain, B) :
    if remain == 0 : return
    if ord('A')-55 <= remain%B and remain%B <= ord('Z')-55 :
        result.insert(0, chr(remain%B + 55))
    else :
        result.insert(0, remain%B)
    getNotationValue(remain//B, B)

data = input().split()

value = int(data[0])
notation = int(data[1])

result = []

getNotationValue(value, notation)

for v in result: print(v, end='')
