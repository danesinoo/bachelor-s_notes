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
% Pesi descritti in una riga:

h = (b-a)/(4*N);

x = a:h:b; x = x';

w=2*h.*[7,repmat([32 12 32 14],1,N-1),32, 12, 32,7]./45;
