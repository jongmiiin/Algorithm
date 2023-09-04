#include <bits/stdc++.h>

using namespace std;

int stair[304];
int dp[4][304];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> stair[i];
	dp[0][0] = stair[0];
	dp[0][1] = dp[0][0]+stair[1];
	dp[1][1] = stair[1];
	for(int i=2;i<n;i++){
		dp[0][i] = dp[1][i-1] + stair[i];
		dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + stair[i];
	}
	cout << max(dp[0][n-1], dp[1][n-1]);
	return 0;
}