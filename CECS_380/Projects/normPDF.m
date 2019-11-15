function f = normPDF(x,mu,variance)

if (variance > 0)
    e = -.5*((x-mu).^2)/variance;
    c = 1/sqrt(variance*2*pi);
    f = c * exp(e);
end
return
end