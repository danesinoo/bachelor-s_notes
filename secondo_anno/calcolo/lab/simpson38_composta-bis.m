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
w = zeros(1,3*N+1);
% primo e ultimo peso
w(1) = 3*h/8 ; 
w(end) = 3*h/8;

ind_trino = 4:3:3*N-1;
w(ind_trino) = 6*h/8;


ind_most = 2:3:3*N-1;
w(ind_disp) = 9*h/8;

ind_most = 3:3:3*N-1;
w(ind_disp) = 9*h/8;

% Pesi descritti in una riga:
% w=h.*[1,repmat([4 2],1,N−1),4,1]./3;
