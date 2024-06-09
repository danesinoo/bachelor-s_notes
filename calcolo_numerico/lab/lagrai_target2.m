function [I] = lagrai_target2(nodi, punti, j)

% nodi - nodi(i) dà la differenza tra x_i e x_j
denomitore = nodi - nodi(j);
denomitore(j) = 1;
coeff = 1 / prod(denomitore);

% matrice triangolare superiore con nodi(i) sulla diagonale
% per cui prod(mat, 1) dà il polinomio (x - x_j)^(n-1)
% mat = triu(ones(length(nodi)), 1) * nodi(j);
mat(mat == 0) = 1;

% da il polinomio di lagrange per il punto j
l = prod(mat, 1) * coeff;


% calcolare il valore del polinomio per ciascun punto
I = punti' * l;
I = sum(I, 2);
	
end

