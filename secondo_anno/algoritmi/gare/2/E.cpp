#include <bits/stdc++.h>
using namespace std;
#define maxn 210

//To avoid precision errors after dividing the square sides by sqrt(2) I'll square everything and multiply by 2 the circle radiuses

int n, m, k;
int houses[maxn], plots[maxn];

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		plots[i] = r*r*2ll;
	}
	for(int i = 0; i < m; i++){
		int r;
		cin >> r;
		houses[i] = r*r*2ll;
	}
	for(int i = 0; i < k; i++){
		int s;
		cin >> s;
		houses[i + m] = s*s;
	}
	
	m += k;
	sort(plots, plots + n);
	sort(houses, houses + m);
	
	int ris = 0;
	int i = 0, j = 0;
	while(i < m && j < n){
		while(j < n && houses[i] >= plots[j])
			j++;
			
		if(j < n){
			i++;
			j++;
			ris++;
		}
	}
	
	cout << ris << endl;
}
