function [output] = sumN(N, f)
output = 0;
for i = 1:N
    output = output + f(i);
end
end