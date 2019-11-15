function [p,fp,ite] = newton_method(f, df, x, M, Tol)
%%f= function
%%df = function's derivative 
%%x = initial guess
%%M = max number of iterations
%%Tol = accuracy of approximated sol

i = 1;
p = 0;
fp = 0;

while i< M
    fp;
    p = x - (f(x)/df(x));
    
    if(abs(p - x) < Tol)
        p;
        ite = i;
        return
    end
    
    i = i + 1;
    x = p;
    fp = f(x);
end
    
    