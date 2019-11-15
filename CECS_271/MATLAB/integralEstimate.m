function [] = integralEstimate(f,a,b)
%%Input:
%f = the function
%a&b = the interval[a,b]

trapzH = b-a;
simpH = (b-a)/2;
midPtH = (b-a)/2;

trapz = (trapzH/2)*(f(a) + f(b));
simp = (simpH/3)*(f(a) + 4*f(a+midPtH) + f(b));
midPt = 2*(midPtH)*(f((a+b)/2));

syms x
p = double(int((sin(x))^2-2*x*sin(x)+1,1.3,.75));

absTrapz = abs((p-trapz)/2);
absSimp = abs((p-simp)/2);
absMidPt = abs((p-midPt)/2);

fprintf("True Value: %f\n", p);
fprintf("Estm. Value for Trapezoidal Method: %f with     Abs. Error: %f\n", trapz, absTrapz);
fprintf("Estm. Value for Simpson Method:     %f with     Abs. Error: %f\n", simp, absSimp);
fprintf("Estm. Value for Midpoint Method:    %f with     Abs. Error: %f\n", midPt, absMidPt);