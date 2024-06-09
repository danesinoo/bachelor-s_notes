clear all;
clc;

f = @(x) (exp(x) ./ (exp(2.*x) + 1));

a = 0;
b = 1;
n = 15;

err_trape = zeros(n, 1);
err_simps = zeros(n, 1);
err_simps38 = zeros(n, 1);
err_booler = zeros(n, 1);

for i = 1:1:n
	[tc, x] = trapezi_composta(a, b, i);
	err_trape(i) = abs(f(x) * tc - (atan(exp(1)) - pi/4));


	[sc, x] = simpson_composta(a, b, i);
	err_simps(i) = abs(f(x') * sc - atan(exp(1)) + pi/4);

	[s38c, x] = simpson38_composta(a, b, i);
	err_simps38(i) = abs(f(x) * s38c - atan(exp(1)) + pi/4);
	

	[bc, x] = boole_composta(a, b, i);
	err_booler(i) = abs(f(x) * bc - atan(exp(1)) + pi/4);
end

x = 1:1:n;

figure(1);
hold on;
semilogy(x, err_trape, 'ro-', x, err_simps, 'bo-', x, err_simps38, 'go-', x, err_booler, 'ko-');
legend('Trapezi composti', 'Simpson', 'Simpson3/8', 'Booler');