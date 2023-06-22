#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int div = n/4, mod = n%4;
	if(mod == 0){
		if(div%2 == 0) cout << 2;
		else cout << 4;
	}
	else{
		if(div%2 == 0) cout << mod;
		else cout << 6-mod;
	}
	return 0;
}