function [H,T]=coinflip(Ntoss)
n=1;
H=0;
T=0;
for i = 1: Ntoss
      n=n+1;
      R = randi([1,2]);
      if R == 1
          H=H+1;
          disp('1')
      end
      if R == 2
          T=T+1;
          disp('0')
      end    
end