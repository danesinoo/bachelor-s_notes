sum = 0;
for i = 1:10
    sum = sum + i;
end

if (sum == 10 * 11 / 2)
    disp("right!")
else
    disp("wrong!")
end