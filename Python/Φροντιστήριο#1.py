#Άρχη
x=input()
x=x.split(',')
a=float(x[0])
b=float(x[1])
c=float(x[2])
li=[a,b,c]
li.sort()
li.reverse()
print('{:1.2f} {:1.2f} {:1.2f}'.format(li[0],li[1],li[2]))
if li[0]<li[1]+li[2]:
    t=(li[0]+li[1]+li[2])/2
    P=2*t
    E=(t*(t-li[0])*(t-li[1])*(t-li[2]))**(1/2)
    print('Perimeter: {:1.2f}'.format(P))
    print('Area: {:1.2f}'.format(E))
    if li[0]==li[1]==li[2]:
        print('Equilateral triangle')
    elif li[0]==li[1] or li[0]==li[2] or li[1]==li[2]:
        print('Isosceles triangle')
    if li[0]**2==(li[1]**2+li[2]**2):
        print('Right triangle')
    elif li[0]**2>(li[1]**2+li[2]**2):
        print('Obtuse triangle')
    else:
        print('Acute triangle')
else:
    print('Not a triangle')
#Τέλος


