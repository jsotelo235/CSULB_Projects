function[p,fp,ite] = NewtonBisect(f,df,a,b,M,Tol)
i = 1;

while i< M
    
    p=a;
    
    if (abs(f(p)) < Tol)
        ite = i;
        fp = f(p);
        break; 
    else
        p = p - (f(p)/df(p));   %Newton
    
        if(p > a && p > b)
            p = (a + b) / 2;
        end
    
        % Bisection
        if(f(p)*f(b) < 0)
            a = p;
        else
            b = p;
        end
        i = i + 1;
    end
end