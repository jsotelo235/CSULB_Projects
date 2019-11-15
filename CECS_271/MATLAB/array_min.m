function min_val = array_min(array)
tic
lowest = array(1);
for i = 2:length(array)
    if(array(i) < lowest)
        lowest = array(i);
    end
end

min_val = lowest;
toc