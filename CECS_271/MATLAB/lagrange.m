function y = lagrange(xdata, ydata, x)

n = length(xdata);
ni = length(x);
L = ones(ni, n+1);

for i = 1:n
    for j=1:n
        if(j~=i)
          L(:,i) = L(:,i).*(x' - xdata(i))/(xdata(j)-xdata(i));
        end
    end
    y = ydata.*L';
end
end
