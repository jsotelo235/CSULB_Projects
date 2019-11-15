function prob_Boy = prob_fam(M, n) 

threeBoys = 0;

for i=1:M
    boys = 0;
    for j=1:5
        rand = randi(n);
        if(rand == 1)
            boys = boys + 1;
        end
    end
    
    if(boys == 3)
        threeBoys = threeBoys + 1;
    end
end

if(n == 2)
    prob_Boy = threeBoys/M;
    disp('Probability birth rate of boy is equal to that of girl')
    disp(prob_Boy);
elseif (n == 3)
    prob_Boy = threeBoys/M;
    disp('Probability birth rate of boy is 1/3 and girl is 2/3')
    disp(prob_Boy);
end
plot(M, prob_Boy, 'k:*')
grid
title('Probability of exact 3 boys in a 5 kids family')
xlabel('Number of iterations')
ylabel('Probability')
end


