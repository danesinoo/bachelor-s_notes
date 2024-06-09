function demo_quadratura()

f = @(x) 1./(x+1);

a = 0;
b = 1;
to = 100;

err_t = zeros(20,1);
err_s = zeros(20,1);
for n=1:to
	t= integrazione_trapezi(f, a, b, n);
	s= integrazione_simpson(f, a, b, n);
	err_t(n) = abs(t- log(2));
	err_s(n) = abs(s- log(2));
end

semilogy(1:to, err_t, 'r', 1:to, err_s, 'b');
legend('trapezi', 'simpson');

end

