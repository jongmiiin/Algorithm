#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(2*n);
	for(int i=0;i<2*n;i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int l = 0, r = 2*n-1, mn = 1e9;
	while(l<r){
		int t = v[l]+v[r];
		mn = min(mn, t);
		l++;
		r--;
	}
	cout << mn;
	return 0;
}