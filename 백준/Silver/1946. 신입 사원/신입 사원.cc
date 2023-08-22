#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, cnt = 1;
		cin >> n;
		vector<pair<int, int>> v;
		for(int i=0;i<n;i++){
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}
		sort(v.begin(), v.end());
		int f = v[0].first, s = v[0].second;
		for(int i=1;i<v.size();i++){
			if(v[i].first>f && v[i].second>s) continue;
			f = v[i].first; s = v[i].second;
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}