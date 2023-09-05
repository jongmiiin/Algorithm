#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag = false, again = false;
	int a, b, n, w, sheep, goat;
	cin >> a >> b >> n >> w;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if(i+j == n && a*i+b*j == w){
				sheep = i; goat = j;
				if(!flag) flag = true;
				else again = true;
			}
		}
	}
	if(!flag || again) cout << -1;
	else cout << sheep << " " << goat;
	return 0;
}