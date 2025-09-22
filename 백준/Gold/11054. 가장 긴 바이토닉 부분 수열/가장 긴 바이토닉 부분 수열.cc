#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	vector<int> arr(n), up_dp(n, 1), down_dp(n, 0);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[j]<arr[i] && up_dp[j]>=up_dp[i]) up_dp[i]++;
	for(int i=n-2;i>=0;i--)
		for(int j=n-1;j>i;j--)
			if(arr[j]<arr[i] && down_dp[j]>=down_dp[i]) down_dp[i]++;
	for(int i=0;i<n;i++)
		ans = max(ans, up_dp[i]+down_dp[i]);
	cout << ans;
	return 0;
}