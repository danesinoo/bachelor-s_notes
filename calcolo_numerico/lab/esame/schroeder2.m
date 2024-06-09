function [x,xall,iter] = schroeder2(f,Df,Df2, x0,tol,max_iter)

% Iterazione di Newton per la soluzione di equazioni nonlineari
% -------------- Inputs ------------------------------------------
%               f        funzione di cui vogliamo trovare lo zero
%               Df       derivata di f
%               Df2      derivata seconda di f
%               x0       valore iniziale 
%               tol      tolleranza per la condizione di arresto
%               max_iter numero massimo di iterazioni
% -------------- Outputs -----------------------------------------
%               x        soluzione finale
%               xall     vettore con tutte le iterazioni
%               iter     numero di iterazioni
% ----------------------------------------------------------------

num = @(x) f(x) * Df(x);
den = @(x) (Df(x))^2 - f(x) * Df2(x);

if den(x0) == 0
	error('Il denominatore è nullo!');
	return
end

% Prima iterazione del metodo di Schroeder
x = x0 - num(x0) / den(x0);    % prima interata
iter = 1;
xall(iter) = x;

while (abs(x - x0) > tol) && (iter < max_iter)           % ciclo iterativo
  x0 = x;
  if den(x) == 0 
      break 
  end

  x = x0 - num(x0) / den(x0);    % nuova iterazione
  iter = iter + 1;              % nuovo numero di iterazione
  xall(iter) = x;
end

end
