clear all;
clc;

value = lagrai_target([1,2,3,4,5,6,7,8,9,10], [3, 24, 5, 1, 31, 58, 2, -1]', 3);
disp(value);

value = lagrai_target2([1,2,3,4,5,6,7,8,9,10], [3, 24, 5, 1, 31, 58, 2, -1], 3);
disp(value)