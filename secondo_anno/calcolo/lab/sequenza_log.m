function [next] = sequenza_log(x, n)

f = @(x, n) ((2 ^ n) * (sqrt((1 + x)/(2 ^ (n -1))) - 1));

if x > -1
    next = zeros(n, 1);
    next(1) = x;
    for i = 2:1:n
        next(i) = f(next(i - 1), i);
    end

else
    disp("Error: x_n <= -1!");
    next = 0;
end

end


