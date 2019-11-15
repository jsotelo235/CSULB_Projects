function [t,w] = eulers(a,b,N,alpha)

h = (b-a)/N;
t(1) = a;
w(1) = alpha;

for i = 1:N
    t(i+1) = t(i)+h;
    w(i+1) = w(i) + h*f(t(i),w(i));
end
end