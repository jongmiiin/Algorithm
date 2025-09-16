#include <bits/stdc++.h>

using namespace std;

int cnt;

void dfs(vector<int>& v, vector<bool>& visited, vector<bool>& finished, int now){
	visited[now] = true;
	int next = v[now];
	if(!visited[next]) dfs(v, visited, finished, next);
	else if(!finished[next]){
		for(int i=next;i!=now;i=v[i])
			cnt++;
		cnt++;
	}
	finished[now] = true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cnt = 0;
		vector<int> v(n+1);
		vector<bool> visited(n+1, false);
		vector<bool> finished(n+1, false);
		for(int i=1;i<=n;i++)
			cin >> v[i];
		for(int i=1;i<=n;i++)
			if(!visited[i]) dfs(v, visited, finished, i);
		cout << n-cnt << '\n';
	}
	return 0;
}