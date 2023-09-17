#include <bits/stdc++.h>

using namespace std;

int mx_dp[4][4];
int mn_dp[4][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	mx_dp[0][0] = a; mn_dp[0][0] = a;
	mx_dp[1][0] = b; mn_dp[1][0] = b;
	mx_dp[2][0] = c; mn_dp[2][0] = c;
	for(int i=1;i<n;i++){
		cin >> a >> b >> c;
		mx_dp[0][1] = a + max(mx_dp[0][0], mx_dp[1][0]);
		mx_dp[1][1] = b + max(mx_dp[0][0], max(mx_dp[1][0], mx_dp[2][0]));
		mx_dp[2][1] = c + max(mx_dp[1][0], mx_dp[2][0]);
		mn_dp[0][1] = a + min(mn_dp[0][0], mn_dp[1][0]);
		mn_dp[1][1] = b + min(mn_dp[0][0], min(mn_dp[1][0], mn_dp[2][0]));
		mn_dp[2][1] = c + min(mn_dp[1][0], mn_dp[2][0]);
		mx_dp[0][0] = mx_dp[0][1]; mn_dp[0][0] = mn_dp[0][1];
		mx_dp[1][0] = mx_dp[1][1]; mn_dp[1][0] = mn_dp[1][1];
		mx_dp[2][0] = mx_dp[2][1]; mn_dp[2][0] = mn_dp[2][1];
	}
	cout << max(mx_dp[0][0], max(mx_dp[1][0], mx_dp[2][0])) << " " << min(mn_dp[0][0], min(mn_dp[1][0], mn_dp[2][0]));
	return 0;
}