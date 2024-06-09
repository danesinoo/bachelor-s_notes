function [res, lengthRes] = puntofisso(g, x0, tol, nIter)

res = [g(x0)];

for i = 2:1:nIter
	res = [res, g(res(i-1))];

	if abs(res(i) - res(i-1)) < tol
        lengthRes = length(res);
		return;
	end
end

lengthRes = length(res);

end
