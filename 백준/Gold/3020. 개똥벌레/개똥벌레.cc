#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, h;
	cin >> n >> h;
	vector<int> up(h+1, 0), down(h+1, 0);
	for(int i=0;i<n/2;i++){
		int a, b;
		cin >> a >> b;
		down[a]++;
		up[h-b+1]++;
	}
	int cnt = n/2, mn = 1e9, mn_cnt = 0;
	for(int i=1;i<=h;i++){
		cnt-=down[i-1];
		cnt+=up[i];
		if(mn==cnt) mn_cnt++;
		if(mn>cnt){
			mn = cnt;
			mn_cnt = 1;
		}
	}
	cout << mn << " " << mn_cnt;
	return 0;
}