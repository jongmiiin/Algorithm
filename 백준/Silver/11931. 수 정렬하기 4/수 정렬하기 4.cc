#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		pq.push(t);
	}
	while(!pq.empty()){
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}