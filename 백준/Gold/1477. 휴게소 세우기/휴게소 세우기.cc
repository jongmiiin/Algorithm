#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> v;
	v.push_back(0); v.push_back(l);
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int st = 1, en = l-1, ans = 1e9;
	while(st<=en){
		int cnt = 0, mid = (st+en)/2;
		for(int i=1;i<v.size();i++){
			int dif = v[i]-v[i-1];
			if(dif%mid == 0) cnt += dif/mid-1;
			else cnt += dif/mid;
		}
		if(cnt>m) st = mid+1;
		else{
			ans = mid;
			en = mid-1;
		}
	}
	cout << ans;
	return 0;
}