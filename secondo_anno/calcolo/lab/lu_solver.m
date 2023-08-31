function x=lu_solver(A, b)

	% LU decomposition
	[L, U, P] = lu(A);

	% Solve Ly = Pb
	y = L\(P*b);

	% Solve Ux = y
	x = U\y;

end
