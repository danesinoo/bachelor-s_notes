#include <bits/stdc++.h>
using namespace std;
#define maxn 10

//using bitmasks: https://codeforces.com/blog/entry/18169

int n;
int s[maxn], b[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i] >> b[i];
    
    int min_diff = 1000000000;
    for(int mask = 1; mask < (1<<n); mask++){
        int sour = 1,bitter = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)){
                sour *= s[i];
                bitter += b[i];
            }
        }
        
        min_diff = min(min_diff, abs(sour - bitter));
    }
    
    cout << min_diff << endl;
}
