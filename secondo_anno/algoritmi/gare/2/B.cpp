#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define maxn 110
#define eps 1e-7

struct scudo{
    ld l,u,f;
}scudi[maxn];

int n;
ld x,y;

ld calc(ld v){
    ld som = 0.0, dist = 0.0;
    for(int i=0;i<n;i++){
        som += scudi[i].u - scudi[i].l;
        dist += (scudi[i].u - scudi[i].l) * scudi[i].f * v;
    }
    dist += (y-som) * v;
    return dist;
}

int main(){
    cin >> x >> y;
    cin >> n;
    
    for(int i=0;i<n;i++)
        cin >> scudi[i].l >> scudi[i].u >> scudi[i].f;
    
    ld f = -1e18, t = 1e18;
    while(t-f > eps){
        ld mid = (t+f)/2.0;
        if(calc(mid) > x)
            t = mid;
        else
            f = mid;
    }
    
    cout << fixed << setprecision(10);
    cout << f << "\n";
}
