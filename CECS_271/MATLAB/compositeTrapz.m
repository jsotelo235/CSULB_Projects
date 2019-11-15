function [] = compositeTrapz(f,a,b,M)
%Input:
% f- is the integrand input
% a and b are upper and lower limits
% M is the number of subintervals

h = (b-a)/M;
sum = 0;

for i=1:(M-1)
    x = a + (i*h);
    sum = sum + f(x);
end
resultTrapz = (h/2)*(f(a)+2*sum + f(b));
fprintf("%f\n", resultTrapz);
end