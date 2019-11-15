function [heads,tails] = Coin_toss(n)
heads = 0;
tails = 0;
p = 0.5;
for i=1:n
    if rand(1,1) < p
    heads = heads+1;
    disp('1')
    else
    tails = tails + 1;
    disp('0')
    end
end
end