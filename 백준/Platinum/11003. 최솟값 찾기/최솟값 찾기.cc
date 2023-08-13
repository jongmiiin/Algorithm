#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l;
	cin >> n >> l;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i=1;i<=n;i++){
		int t, st = i-l+1;
		cin >> t;
		pq.push({t, i});
		while(pq.top().second < st) pq.pop();
		cout << pq.top().first << " ";
	}
	return 0;
}