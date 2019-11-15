function [q0, q1, p] = secant_method(f, p0, p1, M, Tol)
%%f= function
%%df = function's derivative 
%%x = initial guess
%%M = max number of iterations
%%Tol = accuracy of approximated sol

i = 2;
q0 = f(p0);
q1 = f(p1);

while i <= M
    p = p1 - q1*(p1-p0)/(q1-q0);
    
    if(abs(p - p1) < Tol)
        p;
        return
    end
    
    i = i + 1;
    
    %%update p0, q0, p1, q1
    p0 = p1;
    q0 = q1;
    p1 = p;
    q1 = f(p);
end
