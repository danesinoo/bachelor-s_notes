function [x,xall,iter] = bisezione(f,a,b,x0,tol,max_iter)

% Metodo di bisezione per la rierca di zeri di funzione
% ----------- Inputs -------------------------------
%  f   : funzione (inline) di cui vogliamo lo zero
%  a,b : estremi dell'intervallo
%  x0  : punto iniziale
%  tol : tolleranza 
%  max_it: numero massimo di iterazioni
%------------ Outputs ------------------------------
%  x   : la soluzione
%  xall: tutti i punti medi dell'iterazione
%  iter: numero d'iterazioni fatte
%---------------------------------------------------
if f(a)*f(b) > 0 
   error('Metodo delle corde non applicabile');
elseif f(a)*f(b) == 0 
   error('La funzione e'' zero su uno dei bordi');
end

iter = 1;         % iter = n + 1 (nella lezione di teoria)       
x = x0 - (b-a)/(f(b) - f(a))*f(x0);  % prima iterata
xall(iter) = x;   % salva il primo punto 
						% ancora due punti)
   
while (abs(x - x0) > tol) && (iter <  max_iter)  % continua se condizioni soddisfatte
	x0 = x;                                  % salva il vecchio x
	x = x0 - (b-a) / (f(b)-f(a)) * f(x);      % calcola il nuovo x
	iter = iter + 1;                         % incrementa il contatore
    xall(iter) = x;                          % salva il nuovo punto medio
    
end 
