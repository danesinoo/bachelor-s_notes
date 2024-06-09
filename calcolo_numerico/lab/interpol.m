function t = interpol(x, y, s)

m = length(x) -1;
coeff = polyfit(x, y, m);
t = polyval(coeff, s);

end
