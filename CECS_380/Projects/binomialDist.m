function pdf = binomialDist(x,n,p)

pdf=zeros(size(x));
for i=1:length(x)
    if (x(i)>=0)&&(x(i)<=n)
        pdf(i)=p^x(i)*(1-p)^(n-x(i))*factorial(n)/(factorial(n-x(i))*factorial(x(i)));
    end
end
end
