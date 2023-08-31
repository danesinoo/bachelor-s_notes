clear all;
clc;

f = @(x) sin(2*x) - x.^2 + 0.5;

x = linspace(-5, 5, 100);

y = f(x);
yp = y + 0.5*rand(size(y));

d = 4;

V = fliplr(vander(x));
A = V(:,1:d+1);

c = A' * A \ (A' * yp');

I = linspace(-5, 5, 1000);

figure(1)
plot(I, f(I), 'r', I, polyval(c, I), 'b')
legend('f(x)', 'eq_normali(x)')

Q = A;
[Q, R] = qr(A);

c2 = R \ (Q' * yp');
figure(2)
plot(I, f(I), 'r', I, polyval(c2, I), 'b')
legend('f(x)', 'dec_qr(x)')

fprintf('diff norma infinito: %1.5e\n', max(abs(c - c2)))
