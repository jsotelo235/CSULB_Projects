function prob_die = prob_fair_die(M)

threeFives = 0;

for i=1:M
    count = 0;
    for j=1:8
        rand = randi(5);
        if (rand == 5)
            count = count + 1;
        end
    end
    
    if (count == 3)
        threeFives = threeFives + 1;
    end
end

prob_die = threeFives/M;
disp(prob_die)
plot(M, prob_die, 'k:*')
grid
title('Probability of 3 times of "5" in 8 throws')
xlabel('Number of iterations')
ylabel('Probability')
end