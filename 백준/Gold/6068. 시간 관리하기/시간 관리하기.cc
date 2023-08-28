#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++){
		int t, s;
		cin >> t >> s;
		v.push_back({s, t});
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ans = v[0].first - v[0].second;
	for(int i=1;i<n;i++){
		if(ans>v[i].first){
			if(v[i].first-v[i].second>=ans) ans -= v[i].second;
			else ans = v[i].first-v[i].second;
		}
		else ans -= v[i].second;
	}
	cout << (ans<0?-1:ans);
	return 0;
}