function [p,fp,ite] = mod_newton(f, df, dff, x, M, Tol)
%%f= function
%%df = function's derivative 
%%x = initial guess
%%M = max number of iterations
%%Tol = accuracy of approximated sol

i = 1;
p = 0;
fp = 0;

while i< M
    
    p = x - (f(x)*df(x)/(df(x))^2 - f(x)*dff(x));
    
    if(abs(p - x) < Tol)
        p;
        ite = i;
        return
    end
    
    i = i + 1;
    x = p;
    fp = f(x);
end
    
    