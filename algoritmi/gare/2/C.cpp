#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        map<int,int>last_pos;
        int x, mam = 0, ris = 0;
        for(int i=1;i<=n;i++){
            cin>>x;
            
            mam = max(mam,last_pos[x]);
            last_pos[x] = i;
            
            ris = max(ris, i - mam);
        }
        
        cout << ris << "\n";
    }
}
