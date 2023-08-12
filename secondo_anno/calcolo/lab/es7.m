f1 = @(x) (1- cos(x) / x .^2);
f2 = @(x) (1/2 * (sin(x ./ 2) .^2) / (x ./2) .^2);

disp(f1(1.2e-5))
disp(f2(1.2e-5))