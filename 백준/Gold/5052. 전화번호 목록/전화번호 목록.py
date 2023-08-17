import sys
input = sys.stdin.readline

class Node() :
    def __init__(self, value) :
        self.value = value
        self.link = []
        self.linkValue = []

def findLeaf(root) :
    global leaf

    if  len(root.link) == 0 :
        leaf += 1
        return
    
    for l in root.link : findLeaf(l)


testCase = int(input())


for _ in range(testCase) :
    count = int(input())

    leaf = 0

    root = Node(0)

    for _ in range(count) :
        num = input().rstrip()
        current = root

        for n in num :
            node = Node(int(n))
            if int(n) not in current.linkValue :
                current.link.append(node)
                current.linkValue.append(int(n))
                current = node
            else : 
                for k in current.link :
                    if k.value == int(n) :
                        current = k

    # 트리 순회
    findLeaf(root)

    if leaf == count : print('YES')
    else : print('NO')