function [x,xall,iter] = corde(f,a,b,x0,tol,max_iter)

% Metodo delle corde per la soluzione di equazioni nonlineari
% -------------- Inputs ------------------------------------------
%               f        funzione di cui vogliamo trovare lo zero
%               a,b      estremi dell'intervallo
%               x0       valore iniziale 
%               tol      tolleranza per la condizione di arresto
%               max_iter numero massimo di iterazioni
% -------------- Outputs -----------------------------------------
%               x        soluzione finale
%               xall     vettore con tutte le iterazioni
%               iter     numero di iterazioni
% ----------------------------------------------------------------

if f(a)*f(b) > 0 
   error('Metodo delle corde non applicabile');
elseif f(a)*f(b) == 0 
   error('La funzione e` zero su uno dei bordi');
end

q = (f(b)-f(a))/(b-a);   
x = x0 - f(x0)/q;             % prima iterata
iter = 1;
xall(iter) = x;

while (abs(x-x0) > tol) && (iter < max_iter)           % ciclo iterativo
  x0 = x;
  x = x0 - f(x0)/q;                                              % nuova iterazione
  iter = iter + 1;                                    % nuovo numero di iterazione
  xall(iter) = x;
end

end

