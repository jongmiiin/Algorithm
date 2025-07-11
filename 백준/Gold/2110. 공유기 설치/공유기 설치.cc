#include <bits/stdc++.h>

using namespace std;

int n, c, ans;
vector<int> v;

bool is_possible(int dis){
	int cnt = 1, ex_house = v[0];
	for(int i=1;i<n;i++){
		if(v[i]-ex_house>=dis){
			cnt++;
			ex_house = v[i];
		}
	}
	return (cnt>=c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> c;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int l = 0, r = v[n-1];
	while(l<=r){
		int mid = (l+r)/2;
		if(is_possible(mid)){
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	cout << ans;
	return 0;
}