#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second

//Greedy approach: sort all activities by increasing ending time, then assign them to classrooms (if possible) in this order

vector<pii> v;
int n, k;
multiset<int> se;
int ris;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        se.insert(0);
    
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].se >> v[i].fi;
    
    sort(v.begin(), v.end());
    
    for(auto p:v){
        auto it = se.lower_bound(p.se);
        if(it != se.begin()){
            it--;
            se.erase(it);
            ris++;
            se.insert(p.fi);
        }
    }
    
    cout<<ris<<"\n";
}
