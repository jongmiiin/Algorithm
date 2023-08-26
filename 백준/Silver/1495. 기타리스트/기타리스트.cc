#include <bits/stdc++.h>

using namespace std;

int dp[54][1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s, m;
	cin >> n >> s >> m;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		if(i == 0){
			if(s+t<=m) dp[i][s+t]++;
			if(s-t>=0) dp[i][s-t]++;
		}
		else{
			for(int j=0;j<=m;j++){
				if(dp[i-1][j] && j+t<=m) dp[i][j+t]++;
				if(dp[i-1][j] && j-t>=0) dp[i][j-t]++;
			}
		}
	}
	bool flag = true;
	for(int i=m;i>=0;i--){
		if(dp[n-1][i]){
			flag = false;
			cout << i;
			return 0;
		}
	}
	if(flag) cout << -1;
	return 0;
}