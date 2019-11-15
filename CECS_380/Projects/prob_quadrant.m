function prob_same_points = prob_quadrant(M)

for i=1:M
    count = 0;  % Variable to keep track if we have three points in the same quadrant
    
    for k=1:i
        %Generate random numbers from the sample interval [0,360].
        randomNums = randi([0,360],3,1);
        points = sort(randomNums);
        
        temp1 = points(3) - points(1);
        temp2 = points(3) - points(2);
        
        if(temp1 <= 90 && temp2 <= 90)
            count = count + 1;
        else
            count = 0;
        end
    end

    prob_same_points(i) = (count/k);
end
plot(prob_same_points)
    grid
    title('Probability of three random number land in the same quadrant')
    xlabel('Number of iterations')
    ylabel('Probability')
end
