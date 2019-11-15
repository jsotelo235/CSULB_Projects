function [] = Chi_Square(degFreedom_1, degFreedom_2)

x_data = (0:0.1:10);
chi_sq_1 = chi2pdf(x_data,degFreedom_1); % degree of freedom 1
chi_sq_2 = chi2pdf(x_data,degFreedom_2);% degree of freedom 10

figure 
ax1 = subplot(2,1,1);
plot(ax1, x_data, chi_sq_1, 'r-')
title('Degree of Freedom 1');
xlabel('x');
ylabel('y');
grid on 

ax2 = subplot(2,1,2);
plot(ax2, x_data, chi_sq_2, 'b--')
title('Degree of Freedom 10');
xlabel('x');
ylabel('y');
grid on
end