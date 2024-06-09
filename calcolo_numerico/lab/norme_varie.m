function norma = norme_varie(x, p)
	if (p > 2 && p ~= Inf)
		fprintf('p deve essere 1, 2 o Inf\n');
		return;
	end

	s = size(x);
	disp(s);
	fprintf("size s: ");
	disp(size(s));

	x = abs(x);

	% se x è una matrice
	if s(1) ~= 1 && s(2) ~= 1
		if (p == Inf)
			return norme_varie(x', 1);
		end

		if (p == 1)
			norma = max(sum(x));
			return;
		end

		if (p == 2)
			e = eig(x' * x); % autovalori e autovettori di x' * i
			norma = max(abs(e)) .^ (1 / 2);
			return;
		end

	% se x è un vettore
	elseif length(s) == 2
		if (p == Inf)
			norma = max(x);
			return;
		end
		norma = sum(x .^ p) ^ (1 / p);
		return;
	
	else
		fprintf('x deve essere un vettore o una matrice m x n\n');
		return;

	end
end

