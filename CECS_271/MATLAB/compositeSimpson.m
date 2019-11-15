function [] = compositeSimpson(f,a,b,n)

simpH = (b-a)/n;
sumEven = 0;
sumOdd = 0;

for i = 1:(n/2)-1
    x = a + 2*i*simpH;  %even index 
    sumEven = sumEven + f(x);
end

for j = 1:(n/2)
    x = a + (2*j - 1)*simpH;%odd index
    sumOdd = sumOdd + f(x);
end

syms x
%t = double(int(1/(x+4),0,2));

compSimp = (simpH/3)*(f(a) + 2*sumEven + 4*sumOdd + f(b));
%relError = abs((compSimp-trueVal)/trueVal);

fprintf("Composite Simpson %f Relative Error %f\n", compSimp);
end