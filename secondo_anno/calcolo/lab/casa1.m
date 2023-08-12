I = linspace(-3, 3);
f = @(x) (cosh(x));
p = @(x) (1 + (1/2)*x.^2 + (1/24)* x.^4);
err = @(x) (abs(f(x) - p(x)));

figure(1);
title("f and taylor(f)");

hold on;
plot(I, f(I));
plot(I, p(I));
hold off;

figure(2);
title("err");
plot(I, err(I));

figure(3);
title("err, logy");
plot(I, err(I));