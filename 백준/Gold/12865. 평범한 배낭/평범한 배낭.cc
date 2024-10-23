#include <bits/stdc++.h>

using namespace std;

int dp[100004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	while(n--){
		int w, v;
		cin >> w >> v;
		for(int i=k;i>=w;i--)
			dp[i] = max(dp[i], dp[i-w]+v);
	}
	cout << dp[k];
	return 0;
}