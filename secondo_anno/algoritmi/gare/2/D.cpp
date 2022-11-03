#include <bits/stdc++.h>
using namespace std;
#define maxn 13

int n,m;
vector<int>adj[maxn];
vector<int>mim,tmp;
string nomi[maxn];

int vis[maxn],num;

void ric(int a,int prof){
	if(prof == n){
		tmp.push_back(a);
		if(!mim.size())
			mim = tmp;
		num++;
		tmp.pop_back();
		return;
	}
	vis[a] = 1;
	tmp.push_back(a);
	
	for(auto i:adj[a]){
		if(!vis[i])
			ric(i,prof + 1);
	}
	
	tmp.pop_back();
	vis[a] = 0;
}

void solve(){
	mim.clear(), tmp.clear();
	for(int i=0;i<n;i++)
		vis[i] = 0;
	num = 0;
	
	for(int i=0;i<n;i++)
		ric(i,1);
	
	cout << num << "\n";
	for(auto i:mim){
		cout << nomi[i] << " ";
	}
	cout << "\n"; 
}

int main(){
	int t;
	cin >> t;
	while(t--){
		map<string,int>M;
		string s;
		
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> s;
			M[s] = i;
			nomi[i] = s;
		}

		vector<vector<int>> vicini(n, vector<int>(n, 1)); // ma qui si usano le
                                                          // matrici :)
		cin >> m;
		for(int i=0;i<m;i++){
			int a,b;
			cin >> s, a = M[s];
			cin >> s, b = M[s];
			vicini[a][b] = 0;
			vicini[b][a] = 0;
		}

		for(int i=0;i<n;i++){
			adj[i].clear();
			for(int j=0;j<n;j++){
				if(vicini[i][j])
					adj[i].push_back(j);
			}
		}
		
		solve();
	}
}
