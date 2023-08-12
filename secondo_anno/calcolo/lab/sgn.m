function [sign] = sgn(x)

if x > 0
    sign = 1;
elseif x < 0;
    sign = -1;
else
    sign = 0;
    disp("Input uguale a zero!")
end

end