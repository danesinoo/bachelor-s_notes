function t = interpol2(x, y, s)
% x - vector of x values
% y - vector of y values
% s - vector of x values to interpolate at
%
% output:
% t - vector of interpolated y values at s

t = [];
for i=1:length(x)
	t = [t, lagrai_target(x, s', i)];
end

t = t .* y;

t = sum(t, 2);

end

