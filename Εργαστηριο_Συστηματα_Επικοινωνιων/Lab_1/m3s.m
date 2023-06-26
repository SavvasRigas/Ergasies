function [means, mins, maxs] = m3s(A)
maxs=A(1);
for i=1:length(A)
    if A(i)>maxs
        maxs=A(i);
    end
end
mins=A(1);
for k=1:length(A)
    if A(k)<mins
        mins=A(k);
    end
end
S=sum(A);
L=length(A);
means = S/L;
end