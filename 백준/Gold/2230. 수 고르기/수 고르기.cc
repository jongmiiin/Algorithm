#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 2100000000;
vector<int> v;

void bin_search(int st, int en, int k);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++)
		bin_search(i, n-1, v[i]);
	cout << ans;
	return 0;
}

void bin_search(int st, int en, int k){
	while(st<=en){
		int mid = (st+en)/2;
		if(abs(k-v[mid])>=m){
			if(abs(k-v[mid])<ans) ans = abs(k-v[mid]);
			en = mid-1;
		}
		else st = mid+1;
	}
}