function [x,w] = trapezi_composta(a,b,N)

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
h = (b-a)/N;
% nodi di integrazione
x = a:h:b; x = x';
% pesi di integrazione
w = ones(1,N+1);
w(1) = 1/2; w(end) = 1/2;
w = h*w;

end