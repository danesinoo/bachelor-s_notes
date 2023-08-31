clear all;
clc;

f = @(x) sin(x) + x;

x0 = 3;
h =  @(x) 10 .^ (-x);

sx = @(f, x0, h) (f(x0) - f(x0 - h)) ./ h;
dx = @(f, x0, h) (f(x0 + h) - f(x0)) ./ h;
cx = @(f, x0, h) (f(x0 + h) - f(x0 - h)) ./ (2 .* h);

n = 10;
I = linspace(1, n, n-1);

x = cos(x0) + 1;

err_s = abs(sx(f, x0, h(I)) - x);
err_d = abs(dx(f, x0, h(I)) - x);
err_c = abs(cx(f, x0, h(I)) - x);

semilogy(I, err_s, 'r', I, err_d, 'b', I, err_c, 'b');
legend('sx', 'dx', 'cx');
