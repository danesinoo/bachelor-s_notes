clear all;
clc;

f = @(x) (exp(x) - 2 + x);

figure(1);
nIter = 23; % sono sufficienti 22 iterate per ottenere x  tol
x_2 = linspace(1, nIter, nIter);
x_all = bisezione(f, -1, 1, 10 ^ (-8), nIter);
plot(x_2, x_all);

figure(2);
x = 0.4428544010023885;
semilogy(x_2, abs((x - x_all) / x));
