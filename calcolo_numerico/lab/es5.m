clear all;
clc;

f = @(x) (((1+x) - 1) ./ x);

I = linspace(-1e-10, 1e-10, 2000);
vals = f(I);

figure(1)
plot(I, vals);

figure(2)
plot(I, abs(1 - vals));
