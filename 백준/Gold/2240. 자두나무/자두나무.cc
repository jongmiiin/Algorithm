#include <bits/stdc++.h>

using namespace std;

int plum[1004];
int dp[34][1004][4]; // w t 1/2

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, w, wcnt = 0;
	cin >> t >> w;
	for(int i=0;i<t;i++)
		cin >> plum[i];
	dp[0][0][1] = (plum[0]==1?1:0);
	dp[1][0][2] = (plum[0]==2?1:0);
	for(int i=1;i<t;i++){
		for(int j=0;j<=w && j<=i;j++){
			if(j==0){
				dp[j][i][1] = dp[j][i-1][1]+(plum[i]==1?1:0);
				dp[j][i][2] = dp[j][i-1][2]+(plum[i]==2?1:0);
			}
			else{
				dp[j][i][1] = max(dp[j-1][i-1][2], dp[j][i-1][1])+(plum[i]==1?1:0);
				dp[j][i][2] = max(dp[j-1][i-1][1], dp[j][i-1][2])+(plum[i]==2?1:0);
			}
		}
	}
	int mx = 0;
	for(int i=0;i<=w;i++)
		mx = max(mx, max(dp[i][t-1][1], dp[i][t-1][2]));
	cout << mx;
	return 0;
}