function [t, w] = Eulers_Method(f,a,b,c,N)

%f = function
%a & b = the interval [a,b]
%c = the initial condition
%N = the number of subinterval

h = (b-a)/N;
t = a;
w = c;
x = 0:N;

str_1 = ("---------------------------------------");
str_2 = ("|");

fprintf('i \t\t | \t\t t \t\t | \t\t w\n');

for i=1:length(str_1)
    fprintf(str_1(i));
end
fprintf('\n');

for i=1:length(x)
    w(i+1) = w(i) + h*(f(t(i),w(i)));
    t(i+1) = a + i*h;    
    
    fprintf('%d \t\t %s \t\t %.1f \t %s \t\t %.4f',i-1, str_2, t(i), str_2, w(i));
    fprintf('\n');
end
end 
