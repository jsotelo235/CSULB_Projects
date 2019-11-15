function [out1,out2] = coin(tosses)
x = rand(1,tosses);
p = 0.5;
out1 = x < p;
out2 = sum(out1);
 plot(tosses, out2./tosses)
end
