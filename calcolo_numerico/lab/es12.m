clear all;
clc;

to = 25;
f = @(x) 1./(1.+25.*x.^2);

for n = 1:to
	x = linspace(-1,1,n+1);
	s = linspace(-1,1,1000);
	p = interpol(x,f(x),s);
	p2 = interpol2(x,f(x),s);

	y = f(s);
	figure(n);
	hold on;
	plot(s, p, 'r', s, p2, 'b');
	hold off;
end

