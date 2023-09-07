#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	if(n%2) n++;
	long long ans = 1;
	for(int i=1;i<=n/2;i++){
		ans%=16769023;
		ans*=2;
	}
	cout << ans%16769023;
	return 0;
}