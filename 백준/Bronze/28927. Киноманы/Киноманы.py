s1, t1, m1 = map(int, input().split())
s2, t2, m2 = map(int, input().split())

t_max = s1*3 + t1*20 + m1*120
t_mel = s2*3 + t2*20 + m2*120

if t_max > t_mel: print('Max')
elif t_max < t_mel: print('Mel')
else: print('Draw')