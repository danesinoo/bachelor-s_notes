clear all;
clc;

f = @(x) (cos(2*x)).^2 - x.^2;
Df = @(x) -2 * sin(4*x)-2*x;
D2f = @(x) -8*cos(4*x)-2;

a=0;
b=1;
x = linspace(a,b,100);
sol = fzero(f, 0.5);

figure(1)
hold on
plot(x, f(x), 'b');
plot(x, Df(x), '-.k');
plot(x, D2f(x), '--r');
plot(sol, f(sol), 'go', 'MarkerFaceColor', 'g');
legend('f(x)', 'Df(x)', 'D2f(x)', 'sol');
axis([a b -7 7]);
title("Grafico delle funzioni");

x0 = 0.1;
tol = exp(1)^-8;
nMax = 1000;

[x_b, xall_b, iter_b] = bisezione(f, a, b, tol, nMax);
[x_c, xall_c, iter_c] = corde2(f, a, b, x0, tol, nMax);
[x_n, xall_n, iter_n] = newton(f, Df, x0, tol, nMax);
[x_s, xall_s, iter_s] = schroeder2(f, Df, D2f, x0, tol, nMax);

fprintf("Numero iterate del metodo della bisezione %d\n", iter_b);
fprintf("Numero iterate del metodo delle corde %d\n", iter_c);
fprintf("Numero iterate del metodo di Newton %d\n", iter_n);
fprintf("Numero iterate del metodo di Schroeder %d\n", iter_s);

errB = abs(xall_b - sol);
errC = abs(xall_c - sol);
errN = abs(xall_n - sol);
errS = abs(xall_s - sol);

figure(2);
hold on;
semilogy(1:iter_b, errB, 'bo-');
semilogy(1:iter_c, errC, 'ro-');
legend('errB', 'errC');

figure(3);
hold on;
semilogy(1:iter_n, errN, 'bo-');
semilogy(1:iter_s, errS, 'ko-');
legend('errN', 'errS');

fprintf("Soluzione ottenta con il metodo di Schroeder: %1.6f", x_s);
