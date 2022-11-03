#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	vector<int> v(n);
	for(int &i:v)
		cin >> i;
		
	int f = 0, t = n;
	while(f <= t){
		int h = (f + t/2);
		int n_higher = 0;
		
		for(int i:v){
			if(h <= i)
				n_higher++;
		}
		
		if(n_higher < h)
			t = h - 1;
		else
			f = h + 1;
	}
	
	cout << f - 1 << endl;
}
