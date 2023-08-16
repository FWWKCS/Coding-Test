ascending = [1,2,3,4,5,6,7,8]
descending = ascending[-1::-1]

scales = list(map(int, input().split()))

if scales == ascending :
    print('ascending')
elif scales == descending :
    print('descending')
else :
    print('mixed')
