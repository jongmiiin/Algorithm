#include <bits/stdc++.h>

using namespace std;

int dp[100004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c, n, ans = 1e9;
	cin >> c >> n;
	while(n--){
		int cost, people;
		cin >> cost >> people;
		for(int j=cost;j<100001;j++)
			dp[j] = max(dp[j], dp[j-cost]+people);
	}
	for(int i=1;i<100001;i++)
		if(dp[i]>=c) ans = min(ans, i);
	cout << ans;
	return 0;
}