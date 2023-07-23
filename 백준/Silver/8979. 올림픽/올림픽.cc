#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, pair<int, pair<int, int>>>> v;
	for(int i=0;i<n;i++){
		int num, gold, sil, bro;
		cin >> num >> gold >> sil >> bro;
		v.push_back({gold, {sil, {bro, num}}});
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int cnt = 1;
	if(k == v[0].second.second.second){
		cout << 1;
		return 0;
	}
	bool flag = false;
	for(int i=1;i<n;i++){
		if(v[i].first == v[i-1].first){
			if(v[i].second.first == v[i-1].second.first){
				if(v[i].second.second.first == v[i-1].second.second.first) flag = true;
			}
		}
		if(!flag) cnt++;
		flag = false;
		if(k == v[i].second.second.second){
			cout << cnt;
			return 0;
		}
	}
	return 0;
}