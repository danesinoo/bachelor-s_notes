clear all;
clc;

x = 1;
n = 70;

sl = sequenza_log(x, n);
sl2 = sequenza_log2(x, n);
err = abs(sl - log(x +1));
err2 = abs(sl - log(x +1));
diff = abs(sl - sl2);

figure(1)
hold on
plot(1:1:n, sl);
plot(1:1:n, sl2);


figure(2)
hold on
semilogy(1:1:n, err, '.');
semilogy(1:1:n, err2);
semilogy(1:1:n, err2, 'x');

figure(3)
plot(1:1:n, diff, '.');
