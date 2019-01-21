import re
n, t = map(int, input().split())
s=input()

if '.' in s:
    a, b=s.split('.')
    S=a+'.'+re.sub("[4]{,"+str(t-1)+"}[56789].*","",b)
    if len(S)!=len(s):
        if S[-1]=='.':
            S=str(int(S[:-1])+1)
        else:
            S=S[:-1]+str(int(S[-1])+1)
    print(S)
else:
    print(s)
