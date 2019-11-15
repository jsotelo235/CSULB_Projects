function randNums = normalDist(mean_, stdDeviation)

randNums = randn(1, 2000);
figure; 
hist(randNums, 50);

title('Histogram Chart')
[mean,stdDeviation] = hist(randNums, 50);
figure;
bar(stdDeviation,mean/trapz(stdDeviation,mean));
title('Bar Chart');
end


