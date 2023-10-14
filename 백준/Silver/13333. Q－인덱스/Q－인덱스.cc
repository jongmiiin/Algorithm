#include <bits/stdc++.h>

using namespace std;

int arr[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 1; i <= 1000; i++) {
		int max_cnt = 0;
		int min_cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] >= i) max_cnt++;
			if (arr[j] <= i) min_cnt++;
		}
		if (max_cnt >= i && min_cnt <= i) ans = max(ans, i);
	}
	cout << ans;
	return 0;
}