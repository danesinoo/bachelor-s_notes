f = @(x) (sin(x) + x - 1);

I = linspace(0, 1, 100000);
% Plot the function
figure(1);
plot(I, f(I));

figure(2);

f1 = @(x) (cos(x) + 1);
g = @(x) (x - f(x)/f1(x));


hold on;
plot(I, g(I), 'b');
plot(I, I, 'r');
hold off;

figure(3);
x0 = 0;
[g_all, len] = puntofisso(g, x0, 10 ^(-8), 1000000);
x = 0.510973429388569;
semilogy(1:len, abs(g_all - x) / abs(x));
