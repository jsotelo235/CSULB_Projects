function [y] = LagrangeInterp(xdata, ydata, x)

n = length(xdata);
y = 0;

for i = 1:n
    L = ydata(i);
    for j = 1:n
        if (i~=j)
            L= L * (x-xdata(j))/(xdata(i)-xdata(j));
        end
    end
 
    y = y + L;
end
formatSpec = 'The corresponding y value produced by Lagrange Interpolation is: %f';
fprintf(formatSpec,y)
plot(xdata, ydata, 'rx', x, y, 'ro')

hold on
x = 1:.02:5;
fx = x.^-1;
plot(x,fx,'b')

title('Lagrange Polynomial Interpolation for 1/x')
xlabel('x')
ylabel('y')
end