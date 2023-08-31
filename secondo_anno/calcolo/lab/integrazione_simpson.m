function I=integrazione_simpson(f,a,b, n)

x = linspace(a,b,2*n+1);
h = (b-a)/(2*n);
w0 = h/3;
wpari = 4*h/3;
wdisp = 2*h/3;

I = w0*(f(x(1)) + f(x(end)));
I = I + sum(wpari*f(x(2:2:end-2))) + sum(wdisp*f(x(3:2:end-1)));

end
