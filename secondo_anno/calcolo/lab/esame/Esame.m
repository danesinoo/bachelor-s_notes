clear all;
close all;
clc

f = @(x) cos(2*x).^2 - x.^2;

x0 = 0.1;
tol = 1e-8;
nMax = 1000;
a = 0; b = 1;

x = linspace(a,b,100);

Df = @(x) -2*sin(4*x) - 2*x;
D2f = @(x) -8*cos(4*x) - 2;

sol = fzero(f,0.5);

figure(1)
plot(x,f(x),'b')
hold on
plot(x,Df(x),'-.r')
plot(x,D2f(x),'--k')
plot(sol,f(sol),'bo', 'MarkerFaceColor','g')
legend('f(x)','Df(x)','D2f(x)')
axis([a b -7 7])
grid on
title('Grafico delle funzioni')

[xC,xallC,iterC] = corde(f,a,b,x0,tol,nMax);
[xB,xallB,iterB] = bisezione(f,a,b,tol,nMax);
[xN,xallN,iterN] = newton(f,Df,x0,tol,nMax);
[xS,xallS,iterS] = schroeder(f,Df,D2f,x0,tol,nMax);

fprintf('\n \t Iterate metodo della corda:  %d', iterC)
fprintf('\n \t Iterate metodo di bisezione: %d', iterB)
fprintf('\n \t Iterate metodo di Newton:    %d', iterN)
fprintf('\n \t Iterate metodo di Schroeder: %d \n', iterS)

errC = abs(sol-xallC);
errB = abs(sol-xallB);
errN = abs(sol-xallN);
errS = abs(sol-xallS);

figure(2)
semilogy(1:iterC,errC,'o-b')
hold on;
semilogy(1:iterB,errB,'o-r')
legend('Errore corde', 'Errore bisezione')

figure(3)
semilogy(1:iterN,errN,'o-b')
hold on;
semilogy(1:iterS,errS,'o-r')
legend('Errore Newton', 'Errore Schroeder')

fprintf('\n \t Soluzione ottenuta con il metodo di Schroeder: %1.6f \n',xS)
