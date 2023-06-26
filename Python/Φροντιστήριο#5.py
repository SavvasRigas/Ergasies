#Αρχή
x=0
while x!='END' and x!='end':
    x=input().replace('-','')
    if x=='end' or x=='END':
        break
    H=int(x[:2])+1
    if int(x[2:4])==1 and H==32:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==3 and H==32:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==5 and H==32:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==7 and H==32:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==8 and H==32:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==10 and H==32:
        H=0
        M=int(x[2:4])+1
    if int(x[4:])%4==0 and int(x[2:4])==2 and H==30:
        H=0
        M=int(x[2:4])+1
    if int(x[4:])%4!=0 and int(x[2:4])==2 and H==29:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==4 and H==31:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==6 and H==31:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==7 and H==31:
        H=0
        M=int(x[2:4])+1
    if int(x[2:4])==11 and H==31:
        H=0
        M=int(x[2:4])+1
    if int(x[2:40])==12 and H==32:
        H=0
        M=0
        Y=int(x[4:])+1
    M=int(x[2:4])
    Y=int(x[4:])
    print('{:2d}-{:2d}-{}'.format(H,M,Y))
#Τέλος
        

