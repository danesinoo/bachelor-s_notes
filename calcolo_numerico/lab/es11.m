clear all;
clc;

f = @(x) exp(-2.*x)/3+7*x.^3+x.^2;
to = 39;

cheb = @(i, n) -1*cos(i.*pi./n);

for n = 4:1:to
	

	I = cheb(0:1:n, n);
	y = f(I);

	s = linspace(-1, 1, 500);
	t = interpol(I, f(I), s);

	figure(1);
	hold on;
	plot(s, f(s), 'b');
	plot(s, t, 'r--');
	hold off;

	% errore massimo di interpolazione
	err = max(abs(f(s)-t));
	fprintf('Errore massimo di interpolazione: %2.5e\n', err);
end
