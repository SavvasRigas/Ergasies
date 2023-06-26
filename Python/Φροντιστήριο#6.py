#Αρχή
x=0
def a(apositiveint):
        x = apositiveint // 2
        seen = set([x])
        while x * x != apositiveint:
            x = (x + (apositiveint // x)) // 2
            if x in seen:
                return False
            seen.add(x)
        return True
while x!='end' and x!='END':
    x=input()
    if x=='end' or x=='END':
        break
    c=x.split(',')
    if len(c)==1:
        print('0')
    else:
        if a(len(c))==False:
            print('-1')
            print(len(c))
        else:
            z=int(len(c)**(1/2))
            a=[]
            m2=0
            while m2<=(z-1):
                m1=0
                s=0
                while m1<=(z-1):
                    s=s+int(c[m1+m2*z])
                    m1=m1+1
                m2=m2+1
                a.append(s)
            m4=0
            while m4<=(z-1):
                m3=0
                s=0
                while m3<=(z-1):
                    s=s+int(c[m4+m3*z])
                    m3=m3+1
                m4=m4+1
                a.append(s)
            m5=0
            s=0
            while m5<=(z-1):
                s=s+int(c[m5+m5*z])
                m5=m5+1
            a.append(s)
            m6=0
            s=0
            while m6<=(z-1):
                s=s+int(c[(z-m6)+m6*z-1])
                m6=m6+1
            a.append(s)
            m7=0
            m8=0
            while m7<=(len(c)-2):
                if c[m7]!=c[m7+1]:
                    m8=m8+1
                m7=m7+1
            if c[0]!=c[len(c)-1]:
                m8=m8+1
            m9=1
            m10=0
            while m9<=(len(a)-1):
                if a[0]==a[m9]:
                    m10=m10+1
                m9=m9+1
            m11=0
            while m11<=(len(a)-2):
                m12=m11+1
                m13=0
                while m12<=(len(a)-1):
                    if a[m11]!=a[m12]:
                        m13=m13+1
                    m12=m12+1
                m11=m11+1
            if m10==(len(a)-1) and m8==z:
                print('0')
            else:
                print(m13)
            print(c)
            
            
                        
                
            
            
        
    
    

