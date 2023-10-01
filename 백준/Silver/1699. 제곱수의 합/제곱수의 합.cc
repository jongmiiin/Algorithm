#include <bits/stdc++.h>

using namespace std;

int dp[100004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j*j<=i;j++)
			if(dp[i]>dp[i-j*j]+1 || dp[i] == 0)
				dp[i]=dp[i-j*j]+1;
	cout << dp[n];
	return 0;
}