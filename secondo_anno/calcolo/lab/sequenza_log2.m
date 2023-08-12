function [next] = sequenza_log2(x, n)

f = @(x, n) sqrt(2^(n+1) * sqrt(2 ^ (n - 1) + x) - sqrt(2 ^ (n ^ (2 - 1))));

if x > -1
    next = zeros(n, 1);
    next(1) = x;
    for i = 2:1:n
        next(i) = f(next(i-1), i);
    end
else
    disp("error");
    next = 0;
end

end

