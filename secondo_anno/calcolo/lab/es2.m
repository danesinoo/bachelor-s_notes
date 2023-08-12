I = linspace(0, 2*pi);

f = @(x) (sin(x));
p = @(x) (x - (x .^3) / 6);
err = @(x) (abs(f(x) - p(x)));

figure(1);
title("f and Taylor(f)");

hold on
plot(I, f(I));
plot(I, p(I));
hold off

figure(2);
title("err");
plot(I, err(I))

figure(3);
title("err, logy")
semilogy(I, err(I))