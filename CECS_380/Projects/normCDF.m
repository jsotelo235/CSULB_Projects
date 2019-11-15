function f = normCDF(x,mu,variance)

if (variance > 0)
    
    % e is the value to calculate for the error function
    e = (x-mu)/sqrt(variance*2);
    
    % erf is an error function of matlab
    f = 0.5*(1+erf(e));
end
return
end