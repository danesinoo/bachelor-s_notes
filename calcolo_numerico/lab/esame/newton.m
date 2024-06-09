function [x,xall,iter] = newton(f,Df,x0,tol,max_iter)

% Iterazione di Newton per la soluzione di equazioni nonlineari
% -------------- Inputs ------------------------------------------
%               f        funzione di cui vogliamo trovare lo zero
%               Df       derivata di f
%               x0       valore iniziale 
%               tol      tolleranza per la condizione di arresto
%               max_iter numero massimo di iterazioni
% -------------- Outputs -----------------------------------------
%               x        soluzione finale
%               xall     vettore con tutte le iterazioni
%               iter     numero di iterazioni
% ----------------------------------------------------------------

if Df(x0) == 0 
   error('Warning: Df(x0) = 0');
end

% Prima iterazione del metodo di Newton
dx = -f(x0)/Df(x0);    % primo incremento
x = x0+dx;             % prima iterata
iter = 1;
xall(iter) = x;

while (abs(dx) > tol) && (iter < max_iter)           % ciclo iterativo
  x0 = x;
  if Df(x0) == 0 
      break 
  end
  dx = -f(x0)/Df(x0);                                 % nuovo incremento
  x = x0 + dx;                                        % nuova iterazione
  iter = iter + 1;                                    % nuovo numero di iterazione
  xall(iter) = x;
end

end
