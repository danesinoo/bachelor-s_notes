function sistema_perturbato(A, b, Ap, bp)

	cond = @(A, p) norm(A, p) * norm(inv(A), p);

	x = A\b;
	xp = Ap\bp;

	dA = Ap - A;
	db = bp - b;
	dx = xp - x;

	errA = norm(dA, 1) / norm(A, 1);
	errb = norm(db - b, 1) / norm(b, 1);

	condA = cond(A, 1) * errA;

	if condA_x_err > 1
		fprintf('Il sistema perturbato è mal condizionato\n');
		return;
	end

	sx = norm(dx, 1) / norm(x, 1);
	dx = cond(A, 1) / (1 - condA) * (errA + errb);

	fprintf('Errore relativo su x: %1.2e\n', sx);
	fprintf("Stima dell'errore relativo su x: %1.2e\n", dx);
end
