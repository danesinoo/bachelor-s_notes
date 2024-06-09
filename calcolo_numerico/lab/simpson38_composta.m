function [x,w] = simpson38_composta(a,b,N)

% Formula dei trapezi composta
% -----------------------------
% ---- input ----
% a,b : estremi di integrazione
% N : numero di subintervalli
%
% ---- output ----
% x : nodi di integrazione (vettore colonna)
% w : pesi di integrazione (vettore colonna)

% passo di integrazione
h = (b-a)/(3*N); 
% nodi di integrazione
x = a:h:b; x=x'; 
% pesi di integrazione
w=3*h/8*[1,repmat([3 3 2],1,N-1),3,3,1];
