function [y, relerr] = simpleDev(f,df,x,h)
%%Input
%f = the function
%df = the function derivative
%x = the point to be evaluated
%h = increment

hleng = length(h);

fprintf('\n')
fprintf('h-increment \t Derivative at 1.80 \t Relative error');
fprintf('\n');
fprintf('--------------------------------------------------------\n');
for i = 1:hleng
    
   y = (f(x + h(i)) - f(x))/h(i);
   
   relerr = (abs(df(x) - y))/df(x);
   fprintf('%f \t \t \t %f \t \t \t  %f\n',h(i), y, relerr);
end
end