function [] = pdf_Gamma_Dist(x1,x2)

x_data = x1:0.05:x2;

hold on
graph_gamma_1 = gampdf(x_data,1,1);
graph_gamma_2 = gampdf(x_data,1,5);
graph_gamma_3 = gampdf(x_data,1,10);
graph_gamma_4 = gampdf(x_data,5,1);
graph_gamma_5 = gampdf(x_data,10,1);
graph_gamma_6 = gampdf(x_data,10,2);

grid on
plot(x_data, graph_gamma_1, 'r-');
plot(x_data, graph_gamma_2, 'b-');
plot(x_data, graph_gamma_3, 'g-');
plot(x_data, graph_gamma_4, 'c-');
plot(x_data, graph_gamma_5, 'y-');
plot(x_data, graph_gamma_6, 'm-');
title('Gamma Distribution');
xlabel('x');
ylabel('y');
end