#include <bits/stdc++.h>

using namespace std;

int num[10004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans, mx = 0, mn_sum = 987654321;
	cin >> n;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		num[t]++;
		if(t>mx) mx = t;
	}
	for(int i=1;i<=mx;i++){
		int sum = 0;
		for(int j=1;j<=mx;j++) 
			sum += abs(i-j)*num[j];
		if(sum<mn_sum){
			mn_sum = sum;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}