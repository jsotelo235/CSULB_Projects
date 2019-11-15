function [x,fx,ite]= bisection_method(f,a,b, M, TOL)

% Input
% f = function
% a,b = interval[a,b]
% M = max number of iterations
% Tol = accuracy of approximated solution

i = 0;          
x = 0;
fx = f(x);
ite = 0;

while (i <= M)
    x = (a + (b-a)/2);
    fx = abs(f(a));
    if (abs((x - a)) < TOL)
      x;
      ite = i;
      break;
    end
   
    if((f(a)*f(x)) > 0)
        a = x;
    else
        b = x;
    end
    
    i = i + 1;
end
