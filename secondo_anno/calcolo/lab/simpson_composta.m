function [x,w] = simpson_composta(a,b,N)

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
h = (b-a)/(2*N); 

x = a:h:b; x = x';

% Pesi descritti in una riga:
w=h.*[1,repmat([4,2],1,N-1),4,1]./3;
w = w';
