function [] = centralLimitThm()

n=10000; 

%Step 1) Generate a uniform distribution x(I) between 0-1.
x=rand(1,n);

bin=100;
[h,qs]=hist(x,bin);
hmax=h/max(h);
subplot(3,2,1) % first plot on a 2x3 subplot
bar(qs,hmax);
z=min(x):0.01:max(x);

mu=mean(x);
sigma=std(x);
graph = normpdf(z, mu, sigma);
maxgraph=graph/max(graph);
hold;
plot(z, maxgraph, 'r', 'LineWidth', 3);
title('1) Uniform Distribution x(I) between 0-1');


%Step 2: randomly adding any two x(I) to have another distribution.
for i=1:n
    x(i)=( x(i)+ x(randi(n)) )/2;
end

mu=mean(x);
sigma=std(x);
bin=100;
[h,qs]=hist(x,bin);
mheight=h/max(h);

% Second Plot
subplot(3,2,2)
bar(qs,mheight);
hold;
z=min(x):0.1:max(x);
graph = normpdf(z, mu, sigma);
maxgraph = graph/max(graph);
plot(z, maxgraph, 'r', 'LineWidth', 3);
title('2) Randomly Adding more x(I)');

%Step 3: Do step 2 3 more times.
for m=1:4
    x=rand(1,n);
    for i=1:n
        x(i)=(x(i)+x(randi(n)))/2;
    end
    
    bin=100;
    [h,qs]=hist(x,bin);
    mheight=h/max(h);
    subplot(3,2,m+2);
    bar(qs,mheight);
    hold;
    z=min(x):0.1:max(x);
    
    mu=mean(x);
    sigma=std(x);
    graph= normpdf(z, mu, sigma);
    maxgraph=graph/max(graph);
    plot(z, maxgraph, 'r', 'LineWidth', 3);
    title('3) Adding more x(I) 3 times');
end
