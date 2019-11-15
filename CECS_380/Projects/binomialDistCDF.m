function cdf = binomialDistCDF(x,n,p)

cdf=zeros(size(x));

for i=1:length(x)
    cdf(i)=sum(binomialDistCDF(0:x(i),n,p));
end