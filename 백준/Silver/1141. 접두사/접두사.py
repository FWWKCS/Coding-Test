import sys
input = sys.stdin.readline

class Trie() :
    def __init__(self) :
        self.letter = ''
        self.link = []
        self.next = set()

root = Trie() # 아무 문자도 없는 루트 생성

count = 0
def find_leaf(root) :
    global count
    if len(root.link) == 0 :
        count += 1
        return

    for node in root.link :
        # 링크가 연결된 노드로 이동
        find_leaf(node)

def makeTrie(root, word, depth) :
    if depth == len(word) : return

    # 새로운 문자를 링크해야한다면
    if word[depth] not in root.next :
        # 노드 생성
        Node = Trie()
        Node.letter = word[depth]
        root.next.add(word[depth])
        # 노드 링크
        root.link.append(Node)
        makeTrie(Node, word, depth+1)
    # 이미 있는 문자라면
    else :
        # word[depth]의 값을 가진 문자열로 찾아 이동한다
        for node in root.link :
            if node.letter == word[depth] :
                makeTrie(node, word, depth+1)

N = int(input())
for _ in range(N) :
    word = input().rstrip()
    current = root
    makeTrie(current, word, 0)    

find_leaf(root)

print(count)