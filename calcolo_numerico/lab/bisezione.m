function [next] = bisezione(f, a, b, tol, nIter)

	if (f(a) * f(b) > 0)
		error('La funzione non ha zeri in [a, b]');
	end

	next = zeros(nIter, 1);
	it = linspace(1, nIter, nIter);

	for i=it
		next(i)= (a + b) / 2;

		if (abs(f(next(i))) < tol) || (f(next(i)) == 0)
			return;
		elseif (f(next(i)) * f(a)) < 0
			b = next(i);
		else
			a = next(i);
		end
	end
end
