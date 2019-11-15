function F = NewtonsDivDiff(xdata, ydata, x)

n = size(x,1);
F = 0;
for i = 2:n
    for j = 2:i
        F(i,j) = (F(i, j -1) - F(i-1,j-1))/(xdata(i)- xdata(i-j+1));
    end
end

fx = F(n,n);
for i = n-1:-1:1
    fx = fx*(x-xdata(i)) + F(i,i);
end
