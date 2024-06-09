function [x,xall,iter] = bisezione(f,a,b,tol,max_iter)

% Metodo di bisezione per la rierca di zeri di funzione
% ----------- Inputs -------------------------------
%  f   : funzione (inline) di cui vogliamo lo zero
%  a,b : estremi dell'intervallo
%  tol : tolleranza 
%  max_it: numero massimo di iterazioni
%------------ Outputs ------------------------------
%  x   : la soluzione
%  xall: tutti i punti medi dell'iterazione
%  iter: numero d'iterazioni fatte
%---------------------------------------------------
if f(a)*f(b) > 0 
   error('Metodo di bisezione non applicabile');
elseif f(a)*f(b) == 0 
   error('La funzione e'' zero su uno dei bordi');
end

iter = 1;         % iter = n + 1 (nella lezione di teoria)       
x = (a+b)/2;      % punto medio di [a,b]
xall(iter) = x;   % salva il primo punto medio
   
while (abs(f(x)) > tol) && (iter <  max_iter)  % continua se condizioni soddisfatte
    
    if f(x) == 0           
       return;                               % stop se x e' uno zero
    elseif f(x)*f(a) < 0
       b = x;                                % aggiorna bordo destro b
    elseif f(b)*f(x) < 0
       a = x;                                % aggiorna bordo sinistro a
    end
    
    iter = iter + 1;                         
    x = (a+b)/2;                             % aggiorna punto medio
    xall(iter) = x;                          % salva il nuovo punto medio
    
end 