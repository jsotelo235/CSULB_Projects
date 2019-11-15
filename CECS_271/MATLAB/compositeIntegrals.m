function [] = compositeIntegrals(f,a,b,n)

%%Composite Trapezoidal Method
trapzH = (b-a)/n;
sum = 0;

for i=1:(n-1)
    x = a + (i*trapzH);
    sum = sum + f(x);
end
resultTrapz = (trapzH/2)*(f(a)+2*sum + f(b));
%%End of Composite Trapezoidal Method

%%Composite Midpoint Method
midPtH = (b-a)/(n+2);
sum = 0;

for i = 0:(n/2)
    x = a + (2*i+1)*midPtH;  %even index 
    midComp = f(x);
    sum = midComp + sum;
end
resultMid = 2*(midPtH)*(sum);
%%End of Composite Midpoint Method

%%Composite Simpson Method
simpH = (b-a)/n;
sumEven = 0;
sumOdd = 0;

for i = 1:(n/2)-1
    x = a + (2*i*simpH);        %even index 
    sumEven = sumEven + f(x);
end

for j = 1:(n/2)
    x = a + (2*j - 1)*simpH;    %odd index
    sumOdd = sumOdd + f(x);
end
resultSimp = (simpH/3)*(f(a) + 2*sumEven + 4*sumOdd + f(b));
%%End of Composite Simpson Method

%%True Value
syms x
trueVal = double(int(1/(x+4),0,2));

absErrorTrapz = abs(trueVal - resultTrapz);
absErrorMid = abs(trueVal - resultMid);
absErrorSimp = abs(trueVal - resultSimp);

fprintf("True Value %f\n", trueVal);
fprintf("Composite Trapezoidal Method: %f, with Abs. Error: %f\n", resultTrapz, absErrorTrapz);
fprintf("Composite Midpoint Method:    %f, with Abs. Error: %f\n", resultMid, absErrorMid);
fprintf("Composite Simpson:            %f, with Abs. Error: %f\n", resultSimp, absErrorSimp);
end