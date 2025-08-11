#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<int> v(n+1, 0);
	for(int i=1;i<=n;i++){
		cin >> v[i];
		v[i]+=v[i-1];
	}
	int idx = n, cnt = n+1;
	for(int i=0;i<n;i++){
		if(idx>n-i) idx = n-i;
		while(v[idx+i]-v[i]>=s){
			cnt = min(cnt, idx);
			if(v[idx+i-1]-v[i]<s) break;
			idx--;
		}
	}
	cout << (cnt==n+1?0:cnt);
	return 0;
}