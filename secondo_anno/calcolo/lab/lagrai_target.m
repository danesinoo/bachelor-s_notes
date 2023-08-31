function l = lagrai_target(z,x,i)
%------------------------------------------------
% Calcola l’i-esimo pol. elementare di Lagrange su un vettore di punti di valutazione
%------------------------------------------------
% z = nodi di interpolazione
% x = vettore (colonna!) di punti di valutazione su cui valutare l_i
% i = indice del polinomio
% l = vettore dei valori di l_i sui targets
%------------------------------------------------
n = length(z); m = length(x);
l = prod(repmat(x,1,n-1)-repmat(z([1:i-1,i+1:n]),m,1),2)/...
prod(z(i)-z([1:i-1,i+1:n])); 

% questa è la soluzione di chatgpt,
% dalla soluzione risulta evidente come mai il codice sopra funzioni

% function results = evaluateLagrangePolynomial(nodi, punti, i)
%     % nodi: Vettore dei nodi (x_i) su cui basare i polinomi
%     % punti: Vettore dei punti in cui calcolare i polinomi ℓi
%     % i: Indice i-esimo del polinomio da calcolare
%     
%     numPoints = length(punti);
%     numNodes = length(nodi);
%     
%     results = zeros(numPoints, 1);  % Preallocate the result vector
%     
%     for k = 1:numPoints
%         x = punti(k);
%         li = 1;  % Initialize the Lagrange polynomial
%         
%         for j = 1:numNodes
%             if j ~= i
%                 li = li * (x - nodi(j)) / (nodi(i) - nodi(j));
%             end
%         end
%         
%         results(k) = li;
%     end
% end
end
