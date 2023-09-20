#include <bits/stdc++.h>

using namespace std;

long long dp[104];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, inx = 1;
	cin >> n;
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	dp[4] = 2; dp[5] = 2;
	for(int i=6;i<=100;i++){
		dp[i] = dp[i-1] + dp[inx++];
	}
	while(n--){
		int t;
		cin >> t;
		cout << dp[t] << '\n';
	}
	return 0;
}