#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, mx = 0, mn = 0, ans = 0;
	cin >> n >> m;
	vector<int> plus, minus;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		if(t>0){
			plus.push_back(t);
			mx = max(mx, t);
		}
		else{
			minus.push_back(t);
			mn = min(mn, t);
		}
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	int m_idx = 0, p_idx = plus.size()-1;
	while(m_idx<minus.size()){
		ans += abs(minus[m_idx])*2;
		m_idx+=m;
	}
	while(p_idx>=0){
		ans += plus[p_idx]*2;
		p_idx-=m;
	}
	cout << ans-max(mx, abs(mn));
	return 0;
}		