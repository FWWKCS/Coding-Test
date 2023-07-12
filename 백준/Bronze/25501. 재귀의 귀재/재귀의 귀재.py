import sys
input = sys.stdin.readline

def recursion(s, l, r) :
    global called
    called += 1
    if l >= r : return 1
    elif s[l] != s[r] : return 0
    else :
        return recursion(s, l+1, r-1)
    
def isPalindrome(s) :
    return recursion(s, 0, len(s)-1)

testCase = int(input())

for _ in range(testCase) :
    string = input().strip()
    called = 0
    print(isPalindrome(string), called)