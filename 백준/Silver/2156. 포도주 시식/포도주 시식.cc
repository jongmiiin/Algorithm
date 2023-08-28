#include <bits/stdc++.h>

using namespace std;

int wine[10004];
int dp[4][10004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> wine[i];
	dp[1][0] = wine[0];
	if(n>1) dp[0][1] = max(dp[0][0], dp[1][0]); dp[1][1] = wine[1]; dp[2][1] = dp[1][0] + wine[1];
	for(int i=2;i<n;i++){
		dp[0][i] = max(dp[2][i-1], max(dp[1][i-1], dp[0][i-1]));
		dp[1][i] = dp[0][i-1] + wine[i];
		dp[2][i] = dp[1][i-1] + wine[i];
	}
	for(int i=0;i<3;i++)
		ans = max(ans, dp[i][n-1]);
	cout << ans;
	return 0;
}