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

fprintf('N: %4.4f x_1: %4.4f\n', sl(n), sl(1));
% plot(1:1:n, sl2);
hold off

% figure(2)
% hold on
% semilogy(1:1:n, err, '.');
% semilogy(1:1:n, err2);
% semilogy(1:1:n, err2, 'x');
% hold off
% 
% figure(3)
% plot(1:1:n, diff, '.');
