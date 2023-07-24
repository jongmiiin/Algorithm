#include <bits/stdc++.h>

using namespace std;

int dp[44];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, t;
	cin >> n >> m;
	dp[0] = 1; dp[1] = 1;
	for(int i=2;i<=n;i++)
		dp[i] = dp[i-2] + dp[i-1];
	int inx = 1, cnt = 1;
	for(int i=0;i<m;i++){
		cin >> t;
		cnt *= dp[t-inx];
		inx = t + 1;
	}
	cnt *= dp[n+1-inx];
	cout << cnt;
	return 0;
}