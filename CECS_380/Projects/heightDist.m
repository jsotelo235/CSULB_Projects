function [] = heightDist()
trials=1000;
x=zeros(trials,1);

%books with thicknesses, W, normally distributed between 1 and 3 cm
W=1:3;

%n = stacks of n
n=[1 2 3 4 5 10 15];
bins=10;
a = W(1); 
b = W(3);

mu_w=(a+b)/2;
sig_w=sqrt((b-a)^2/12);

%repeats for every book stacks
p=1;

for B=n
    mu = B*mu_w;
    sig = B^0.5*sig_w;
    
    for k=1:trials
        x(k)=sum((b-a)*rand(B,1)+a); 
    end
    
    % Graphs for n=1,2,10
    if (B==1||B==2||B==10)
        [h, xbar] = hist(x,bins); 
        del=diff(xbar(1:2));
        pdf=h/del; % calculates pdf

        subplot(2,2,p);
        hold;
        bar(xbar,pdf); 
        grid;
        graphF = inline('(1/(sig*sqrt(2*pi)))*exp(-(z-mu).^2/(2*sig^2))');
        z=min(x):0.1:max(x);
        plot(z,graphF(mu, sig, z), 'r','LineWidth', 2)
        title(['Distribution of stack height N =', num2str(B)])
        p=p+1; %p is incremented for subplot
        hold off
    end
end