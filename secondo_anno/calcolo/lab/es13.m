clear all;
clc;

f = @(x) 2 * x + 0.2 + 0.1 * rand(size(x));

n = 20;
I = linspace(0, 1, n);

V = fliplr(vander(I));
A = V(:, 1:3);

y = f(I)';
eq = (A' * A) \ (A' * f(I)');

figure(1);
plot(I, polyval(eq, I), 'b', I, y, 'o', 'MarkerFaceColor', 'g', 'MarkerEdgeColor', 'k');

figure(2);
plot(I, polyval(lu_solver(A, f(I)'), I), 'b', I, y, 'o', 'MarkerFaceColor', 'g', 'MarkerEdgeColor', 'k');

