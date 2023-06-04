# https://www.acmicpc.net/problem/10810

# 첫째 줄에 N (1 ≤ N ≤ 100)과 M (1 ≤ M ≤ 100)이 주어진다.

# 둘째 줄부터 M개의 줄에 걸쳐서 공을 넣는 방법이 주어진다. 
# 각 방법은 세 정수 i j k로 이루어져 있으며, 
# i번 바구니부터 j번 바구니까지에 k번 번호가 적혀져 있는 공을 넣는다는 뜻이다.
#  예를 들어, 2 5 6은 2번 바구니부터 5번 바구니까지에 6번 공을 넣는다는 뜻이다. 
# (1 ≤ i ≤ j ≤ N, 1 ≤ k ≤ N)

# 도현이는 입력으로 주어진 순서대로 공을 넣는다.

# ---------- 출력 ----------

# 1번 바구니부터 N번 바구니에 들어있는 공의 번호를 공백으로 구분해 출력한다. 
# 공이 들어있지 않은 바구니는 0을 출력한다.


# 5 4
# 1 2 3 : 3 3 0 0 0
# 3 4 4 : 3 3 4 4 0
# 1 4 1 : 1 1 1 1 0
# 2 2 2 : 1 2 1 1 0

# 1 2 1 1 0

data = input().split()
setRange = int(data[0])
count = int(data[1])

basket = []
for i in range(setRange): basket.append(0)

for i in range(count) :
    method = input().split()
    a = int(method[0])
    b = int(method[1])
    ballNum = int(method[2])

    for j in range(a,b+1):
        basket[j-1] = ballNum

for i in range(len(basket)) : print(basket[i], end = ' ')