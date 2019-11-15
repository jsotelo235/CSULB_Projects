function result = sumprod(n)
a = 0;
result = 0;
for i = 1: n-1
    a = (i+1)*i;
    result = result + a;
end