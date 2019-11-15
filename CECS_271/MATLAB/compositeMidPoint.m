function [] = compositeMidPoint(f,a,b,n)

midPtH = (b-a)/(n+2);
sum = 0;

for i = 0:(n/2)
    x = a + (2*i+1)*midPtH;  %even index 
    midComp = f(x);
    sum = midComp + sum;
end
result = 2*(midPtH)*(sum);
fprintf("Composite Midpoint Method: %f\n", result);
end