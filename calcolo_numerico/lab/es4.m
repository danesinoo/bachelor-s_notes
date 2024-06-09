N = 500;

f = @(n) (((2 * n) .^ 2) / (2 * n + 1) / (2 * n -1));
apx = zeros(1, N);
apx(1) = f(1);

for i = 2:1:N
    apx(i) = apx(i - 1) * f(i);
end

apx = 2 * apx;

I = 1:1:N;

figure(1);
plot(I, apx);

figure(2);
semilogy(I, abs(pi - apx));