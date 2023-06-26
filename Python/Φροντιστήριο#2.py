#Άρχη
x=0
while x!='END' and x!='end':
    x=input()
    a=x.count('0')
    b=x.count('1')
    c=x.count('2')
    d=x.count('3')
    e=x.count('4')
    f=x.count('5')
    g=x.count('6')
    h=x.count('7')
    i=x.count('8')
    j=x.count('9')
    k=len(x)-(a+b+c+d+e+f+g+h+i+j)
    if a>9:
        a='*'
    if b>9:
        b='*'
    if c>9:
        c='*'
    if d>9:
        d='*'
    if e>9:
        e='*'
    if f>9:
        f='*'
    if g>9:
        g='*'
    if h>9:
        h='*'
    if i>9:
        i='*'
    if j>9:
        j='*'
    if k>9:
        k='*'
    if 'END'==x or 'end'!==x:
        break
    print('{}{}{}{}{}{}{}{}{}{}{}'.format(a,b,c,d,e,f,g,h,i,j,k))
#Τέλος
