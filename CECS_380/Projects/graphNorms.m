function []= graphNorms(x)

subplot(1,2,1) % first plot 
hold;
%calculates normal pdf using a custom pdf function
plot(x, normPDF(x,0,1),'black') 
plot(x, normPDF(x,0,10^-1),'blue') 
plot(x, normPDF(x,0,10.^-2),'red') 
plot(x, normPDF(x,-3,1),'black--') 
plot(x, normPDF(x,-3,10.^-1),'blue--')
plot(x, normPDF(x,-3,10.^-2),'red--') 

xlabel('x')
ylabel('f(x; \mu, \sigma^2)')
title('Norm PDF')
legend('f(x;0,1)','f(x;0,10^{-1})','f(x;0,10^{-2})','f(x;-3,1)','f(x;-3,10^{-1})','f(x;-3,10^{-2})')

subplot(1,2,2) % second plot
hold 
%calculates normal cdf using a custom cdf function
plot(x, normCDF(x,0,1),'black') 
plot(x, normCDF(x,0,10.^-1),'blue') 
plot(x, normCDF(x,0,10.^-2),'red') 
plot(x, normCDF(x,-3,1),'black--') 
plot(x, normCDF(x,-3,10.^-1),'blue--') 
plot(x, normCDF(x,-3,10.^-2),'red--') 

xlabel('x')
ylabel('F(x; \mu, \sigma^2)')
title('Norm CDF')
legend('F(x;0,1)','F(x;0,10^{-1})','F(x;0,10^{-2})','F(x;-3,1)','F(x;-3,10^{-1})','F(x;-3,10^{-2})')

%ANALYSIS: 
%Everytime the Mu value changes, it simply translates the values to the left or right of
%the plot relevant to the mu value.
%The changing the variance of the function makes the graph steeper/lower.
%The lower the variance, the steeper the graph, which shows a 
%smaller disribution of values.

end