#include <bits/stdc++.h>

using namespace std;

int main(){ // 시간복잡도 N^2
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n, 1);
	for(int i=0;i<n;i++)
		cin >> v[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(v[i]>v[j] && dp[j]>=dp[i]) dp[i]++;
	int mx = 1;
	for(int i=0;i<n;i++)
		mx = max(mx, dp[i]);
	cout << mx;
	return 0;
}