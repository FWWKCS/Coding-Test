def cal_sugar(ROW, COL) :
    for r in range(ROW):
        for c in range(COL):
            Table[r][c] = r*3 + c*5
            if Table[r][c] == sugar : return r+c
            
    return -1


sugar = int(input())

ROW = sugar // 3 + 1
COL = sugar // 5 + 1

Table = [[0 for _ in range(COL+1)] for _ in range(ROW+1)]

print(cal_sugar(ROW,COL))