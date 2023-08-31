function I=integrazione_trapezi(f,a,b, n)

x = linspace(a,b,n+1);

I = (f(x(1)) + f(x(n+1)))/2; % primo e ultimo elemento
I = I + sum(f(x(2:n))); % somme degli elementi da x_2 a x_n
I = I*(b-a)/n; % moltiplico per la lunghezza dell'intervallo

end
