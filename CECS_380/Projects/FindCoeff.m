function [] = FindCoeff(x,y)

%Use polyfit to fit a 1st-degree polynomial
coefficients = polyfit(x,y,1);

polyfit(x,y,1);
a = coefficients(1); % returns the slope
b = coefficients(2); % returns the y-intercept

fprintf('coefficient a: %f\n', a);
fprintf('coefficient b: %f\n', b);
formatData = ['y = ' num2str(a) 'x + ' num2str(b) '\n'];
fprintf(formatData);

figure 
ax1 = subplot(2,1,1);
plot(ax1,x,y);
title('x and y original data');
xlabel('x');
ylabel('y');
grid on

ax2 = subplot(2,1,2);
fitted_y = a*x + b;
plot(ax2, x, fitted_y);
title('x and fitted y');
xlabel('x');
ylabel('y');
grid on

end