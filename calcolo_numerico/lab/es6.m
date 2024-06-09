f1 = @(x) ((1 - x) .^ 6);

f2 = @(x) (x .^6 - 6 * x .^5 + 15 * x .^4 - 20 * x .^3 + 15 * x .^2 - 6 * x + 1);

I = @(x) linspace(1 - x, 1 + x, 100);

figure(1)
i = I(0.1);
hold on;
plot(i, f1(i));
plot(i, f2(i));

figure(2)
i = I(0.01);
plot(i, f1(i));
plot(i, f2(i));

figure(3)
i = I(0.005);
plot(i, f1(i));
plot(i, f2(i));

figure(4)
i = I(0.0025);
plot(i, f1(i));
plot(i, f2(i));
