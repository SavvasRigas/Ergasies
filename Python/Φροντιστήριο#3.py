#Αρχή
x=0
while x!='end' and x!='END':
        x=input()
        if x=='end' or x=='END':
                break
        if ' ' in x[:4]:
                print('False')
        else:
                x=x.replace(' ','').replace('-','')
                if len(x)!=16:
                        print('False')
                else:
                        b=['0','1','2','3','4','5','6','7','8','9']
                        c=[]
                        for i in x:
                                if i in b:
                                        c.append(i)
                        if len(c)!=16:
                                print('False')
                        else:
                                if int(c[0])<4 or int(c[0])>7:
                                        print('False')
                                else:
                                        k=0
                                        d=[]
                                        while k<=15:
                                                c[k]=int(c[k])*2
                                                if int(c[k])>=10:
                                                        for j in str(c[k]):
                                                                if j in b:
                                                                        d.append(j)
                                                        c[k]=int(d[0])+int(d[1])
                                                        d.pop()
                                                        d.pop()
                                                k=k+2
                                        m=0
                                        s=0
                                        while m<=15:
                                                s=s+int(c[m])
                                                m=m+1
                                        if s%10==0:
                                                print('True')
                                        else:
                                                print('False')
#Τέλος                                    
                
                                                
                
        
