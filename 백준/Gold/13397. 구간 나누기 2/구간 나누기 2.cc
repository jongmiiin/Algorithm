#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int> v;

bool is_possible(int k){
	int mx = v[0], mn = v[0], cnt = 0;
	for(int i=1;i<n;i++){
		mx = max(mx, v[i]);
		mn = min(mn, v[i]);
		if(mx-mn>k){
			mx = v[i];
			mn = v[i];
			cnt++;
		}
	}
	return (++cnt<=m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.assign(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	int st = 0, en = 10000;
	while(st<=en){
		int mid = (st+en)/2;
		if(is_possible(mid)){
			ans = mid;
			en = mid-1;
		}
		else st = mid+1;
	}
	cout << ans;
	return 0;
}