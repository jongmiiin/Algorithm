#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	if(n<=k){
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	vector<int> dis;
	for(int i=1;i<n;i++)
		dis.push_back(v[i]-v[i-1]);
	sort(dis.begin(), dis.end());
	for(int i=0;i<n-k;i++)
		ans+=dis[i];
	cout << ans;
	return 0;
}