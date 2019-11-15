function [mean_, stdDeviation, variance_] = randomNums(num)

randNum = rand(1, num)-0.5;

mean_ = mean(randNum);
stdDeviation = std(randNum);
variance_ = var(randNum);

meanFormatSpec = 'Mean of random number is %f\n';
fprintf(meanFormatSpec, mean_);

stdFormatSpec = 'Standar Deviation of random numbers is %f\n';
fprintf(stdFormatSpec, stdDeviation);

varianceSpecFormat = 'Variance of random numbers is %f\n';
fprintf(varianceSpecFormat, variance_);

histogram(randNum);
title('Histogram of random numbers');
xlabel('x axis');
ylabel('y axis');
end
