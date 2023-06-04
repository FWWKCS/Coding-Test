# https://www.acmicpc.net/problem/2941

# 단어가 주어졌을 때, 
# 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

# dž는 무조건 하나의 알파벳으로 쓰이고, 
# d와 ž가 분리된 것으로 보지 않는다
# lj와 nj도 마찬가지이다

# 위 목록에 없는 알파벳은 한 글자씩 센다.


word = input()
CroatiaLetter = ['c=','c-','d-','dz=','lj','nj','s=','z=']

# replace는 변경된 값을 반환하고, 기존 변수를 바꾸지않는다
# 따라서 변수 갱신이 필요한 경우 어떤 변수에 할당해서 값을 저장해야한다. 
for i in range(len(CroatiaLetter)):
    word = word.replace(CroatiaLetter[i],'1')

print(len(word))